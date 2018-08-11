#多态
class AudioFile:
    def __init__(self, filename):
        #AudioFile 没有存储ext变量的引用这一事实并不能阻止它在子类中访问
        if not filename.endswith(self.ext):
            raise Exception("Invalid file format")

        self.filename = filename

class MP3File(AudioFile):
    ext = "mp3"
    def play(self):
        print("playing {} as mp3".format(self.filename))

class WavFile(AudioFile):
    ext = "wav"
    def play(self):
        print("playing {} as wav".format(self.filename))

class OggFile(AudioFile):
    ext = "ogg"
    def play(self):
        print("playing {} as ogg".format(self.filename))

#鸭子类型
class FlacFile:
    def __init__(self, filename):
        if not filename.endswith(".flac"):
            raise Exception("Invalid file format")

        self.filename = filename

    def play(self):
        print("playing {} as flac".format(self.filename))

def main():
    ogg = OggFile("test.ogg")
    ogg.play()
    mp3 = MP3File("test.mp3")
    mp3.play()
  
if __name__ == "__main__":
    main()
    flac = FlacFile("test.flac")
    flac.play()