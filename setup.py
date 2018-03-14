"""
Oz Prototype
"""

from setuptools import setup
from cmake.setuptools import CMakeExtension, CMakeBuild

setup(
    name='oz',
    version='0.0.1',
    author='Andy Kitchen',
    author_email='kitchen.andy@gmail.com',
    description=__doc__,
    long_description='',
    python_requires='>=3.4',
    ext_modules=[CMakeExtension('oz/_ext')],
    cmdclass=dict(build_ext=CMakeBuild),
    zip_safe=False,
    packages=[
      'oz',
      'oz.game',
      'oz.deuces'
    ],
    install_requires=[
      'torch>=0.3.0',
      'termcolor'
    ],
)
