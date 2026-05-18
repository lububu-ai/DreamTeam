TEMPLATE = subdirs

SUBDIRS += app \
           unitTest

unitTest.depends = app
