#ifndef UTILITY
#define UTILITY

#include <QString>

QString int2Note(int note);
int note2Int(const QString& note); //NYI

QString noteOctave2Filename(int octave, int note);

#endif // UTILITY

