import hashlib
def zna(a):
    s=str(a)
    m=hashlib.md5(s.encode(encoding='utf8')).hexdigest()
    return int(m,16)/1e38

def znb(b):
    s=str(b)
    m=hashlib.sha1(s.encode(encoding='utf8')).hexdigest()
    return int(m,16)/1e47