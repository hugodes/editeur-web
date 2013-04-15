#-------------------------------------------------
#
# Fichier créé par bryan
#
#-------------------------------------------------

QT += gui core
QT += webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LeEdit
TEMPLATE = app


SOURCES += main.cpp\
        leedit.cpp\
        buffer.cc\
        dom.cc\
        facteur.cc\
        ligne.cc\
        noeud.cc\
        noeudtexte.cc

HEADERS  += leedit.h\
        buffer.h\
        dom.h\
        facteur.h\
        ligne.h\
        noeud.h\
        noeudtexte.h

FORMS    += leedit.ui
