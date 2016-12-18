#include "utility.h"

#include <sstream>
#include <iomanip>

#define NOTE_IN_1_OCTAVE 12

QString int2Note(int note) {
    switch(note) {
    case 0:
        return "Do";
        break;
    case 1:
        return "Do#/Ré_b";
        break;
    case 2:
        return "Ré";
        break;
    case 3:
        return "Ré#/Mi_b";
        break;
    case 4:
        return "Mi/Fa_b";
        break;
    case 5:
        return "Mi#/Fa";
        break;
    case 6:
        return "Fa#/Sol_b";
        break;
    case 7:
        return "Sol";
        break;
    case 8:
        return "Sol#/La_b";
        break;
    case 9:
        return "La";
        break;
    case 10:
        return "La#/Si_b";
        break;
    case 11:
        return "Si";
        break;
    default:
        return "Autre";
        break;
    }

    return "Autre";

}

QString noteOctave2Filename(int octave, int note) {
    int note_abs = octave * NOTE_IN_1_OCTAVE + note;
    std::stringstream ss;
    ss << "note/" << 244 + note_abs << "_mcg_f_" << std::setfill('0') << std::setw(3) << note_abs << ".wav";
    return QString::fromStdString(ss.str());
}
