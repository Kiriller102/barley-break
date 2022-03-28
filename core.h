#ifndef CORE_H
#define CORE_H


class BarleyBreak {
public:
    BarleyBreak();
    int GetValue(int i, int j) const;
    int GetMoves() const;
    int GetEmptyI() const;
    int GetEmptyJ() const;
    void ClickReact(int i, int j);
    void RestartGame();
    void StartGame();
    bool IsFinished() const;
private:
    int matr[4][4];
    int ConstMatr_[4][4];
    int moves_;
    int iEmpty_;
    int jEmpty_;
};

#endif // CORE_H
