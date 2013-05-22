#-------------------------------------------------
#
# Fichier créé par bryan
#
#-------------------------------------------------

QT += webkitwidgets
QT += gui core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LeEdit
TEMPLATE = app

# Voir c-unit


SOURCES += main.cpp\
        leedit.cpp\
    editeur.cpp \
    affichageligne.cpp \
    noeudtexte.cc \
    noeud.cc \
    ligne.cc \
    facteur.cc \
    dom.cc \
    buffer.cc \
    recherche.cpp \
    configurationgenerale.cpp \
    apropos.cpp \
    confcouleur.cpp

HEADERS  += leedit.h\
    editeur.h \
    affichageligne.h \
    noeudtexte.h \
    noeud.h \
    ligne.h \
    facteur.h \
    dom.h \
    buffer.h \
    recherche.h \
    configurationgenerale.h \
    apropos.h \
    confcouleur.h

FORMS    += leedit.ui \
            recherche.ui \
    configurationgenerale.ui \
    apropos.ui \
    confcouleur.ui

OTHER_FILES += \
    couleur.conf
