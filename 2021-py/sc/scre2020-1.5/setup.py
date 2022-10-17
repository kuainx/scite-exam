from distutils.core import setup
setup(name='scre2020',  #打包后的包文件名
      version='1.5',
      description='Scre Test Function',
      author='LiDongfang',
      author_email='dfli@smmu.edu.cn',
      url='http://www.smmu.edu.cn ',
      py_modules=['scre'],   #与模块.py的文件名一致
)
print('OK')
f=open('c:/ks/scre.dll','w')
f.write('2020-1-25')
f.close()
