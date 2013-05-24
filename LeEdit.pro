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

SOURCES += \
    main.cpp \
    source/gui/recherche.cpp \
    source/gui/leedit.cpp \
    source/gui/editeur.cpp \
    source/gui/configurationgenerale.cpp \
    source/gui/confcouleur.cpp \
    source/gui/apropos.cpp \
    source/gui/affichageligne.cpp

OTHER_FILES += \
    conf/principal.conf \
    conf/couleur.conf \
    image/leedit.png \
    image/leedit.gif

FORMS += \
    formulaire/recherche.ui \
    formulaire/leedit.ui \
    formulaire/configurationgenerale.ui \
    formulaire/confcouleur.ui \
    formulaire/apropos.ui

HEADERS += \
    headers/gui/recherche.h \
    headers/gui/leedit.h \
    headers/gui/editeur.h \
    headers/gui/configurationgenerale.h \
    headers/gui/confcouleur.h \
    headers/gui/apropos.h \
    headers/gui/affichageligne.h

