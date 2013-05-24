#include "headers/gui/editeur.h"

editeur::editeur(QWidget *parent) : QPlainTextEdit(parent){
    QObject::connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurLine()));
    QObject::connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurLine()));
    highlightCurLine();
}

void editeur::highlightCurLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    QTextEdit::ExtraSelection selection;

    QColor lineColor = QColor(Qt::red).lighter(160);

    selection.format.setBackground(lineColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);

    setExtraSelections(extraSelections);
}


int editeur::miseAJourLignes() {
    return this->document()->lineCount();
}

