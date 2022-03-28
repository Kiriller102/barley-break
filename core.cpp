#include "core.h"
#include <math.h>
#include <set>
#include <QRandomGenerator>

BarleyBreak::BarleyBreak() {
    StartGame();
}

int BarleyBreak::GetValue(int i, int j) const {
    return matr[i][j];
}

int BarleyBreak::GetMoves() const {
    return moves_;
}

int BarleyBreak::GetEmptyI() const {
    return iEmpty_;
}

int BarleyBreak::GetEmptyJ() const {
    return jEmpty_;
}

void BarleyBreak::ClickReact(int i, int j) {
    if ((i == iEmpty_ && abs(j - jEmpty_) == 1) || (abs(i - iEmpty_) == 1 && j == jEmpty_)) {
        std::swap (matr[i][j],matr[iEmpty_][jEmpty_]);
        iEmpty_ = i;
        jEmpty_ = j;
        moves_++;
    }
}

void BarleyBreak::RestartGame() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matr[i][j] = ConstMatr_[i][j];
            if (matr[i][j] == 0) {
                iEmpty_ = i;
                jEmpty_ = j;
            }
        }
    }
    moves_ = 0;
}

void BarleyBreak::StartGame() {
    moves_ = 0;
    QRandomGenerator *rnd = QRandomGenerator::global();
    do {
        std::set<int> nums;
        int i = 0, j = 0;
        while (i != 4) {
            int num = rnd->bounded(0,16);
            if (!(nums.find(num) != nums.end())) {
                matr[i][j] = num;
                ConstMatr_[i][j] = num;
                nums.insert(num);
                if (matr[i][j] == 0) {
                    iEmpty_ = i;
                    jEmpty_ = j;
                }
                j++;
                if (j == 4) {
                    j = 0;
                    i++;
                }
            }
        }
    } while (IsFinished());
}

bool BarleyBreak::IsFinished() const {
    int num = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matr[i][j] != num)
                return false;
            num++;
            if (num == 14)
                break;
        }
    }
    if (matr[3][3] == 0)
        return true;
    else
        return false;
}
