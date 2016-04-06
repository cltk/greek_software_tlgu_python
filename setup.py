from setuptools import setup, Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext

ext = Extension('pytlgu',
                ['pytlgu/__init__.pyx',
                 'pytlgu/greek_software_tlgu/tlgu.c'])

setup(
      name='pytlgu',
      description='python wrapper for the tlgu utility',
      version='0.0.1',
      author='Andreas Grivas',
      author_email='andreasgrv@gmail.com',
      cmdclass={'build_ext': build_ext},
      ext_modules=cythonize(ext),
      setup_requires=['pytest-runner'],
      tests_require=['pytest']
      )
