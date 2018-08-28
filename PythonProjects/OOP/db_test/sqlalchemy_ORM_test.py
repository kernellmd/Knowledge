import sqlalchemy as sqa
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class Pet(Base):
    __tablename__ = "pet"
    id = sqa.Column(sqa.Integer, primary_key=True)
    type = sqa.Column(sqa.String(16))
    breed = sqa.Column(sqa.String(32))
    gender = sqa.Column(sqa.Enum("male", "female"))
    name = sqa.Column(sqa.String(64))

engine = sqa.create_engine("sqlite:///mydata.db")
Base.metadata.create_all(engine)


#构建pet对象
pet = Pet()
pet.id = 1
pet.type = "dog"
pet.breed = "spaniel"
pet.gender = "female"
pet.name = "Esme"


#将新创建的对象添加到数据库并保存
Session = sqa.orm.sessionmaker(bind=engine)
session = Session()

session.add(pet)
session.commit()

