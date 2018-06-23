gv = ['a', 'global', 'var']

def func(v):
    gv = [1]
    gv += ['g']
    lv = []
    def inn_func():
        lv = lv + [v]
        gv.insert(1, lv[0])
        return gv
    return inn_func
