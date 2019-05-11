#ifndef POLYOS_H
#define POLYOS_H

#include <set>
#include <vector>

class Cell;
class Element;
class Matrix;
class Piece;


class Pentominoes
{
public:

    virtual ~Pentominoes();

    void Solve(bool countOnly);

protected:

    void Init(Matrix& matrix, std::vector<Piece> const& pieces);

    void AddPieceAspects(Piece const& piece, std::set<Piece>& aspects);

    void AddAspectPlacements(
        Piece const& aspect, 
        std::set<Cell> const& board, 
        std::vector<Piece>& placements
    );

    virtual void BuildBoard(std::set<Cell>& board) = 0;
    virtual bool AspectFilter(Piece const& piece, int flip, int rot);
    virtual bool PlacementFilter(Piece const& aspect, Cell const& pos);

};


class Pentominoes6x10 : public Pentominoes
{
protected:

    void BuildBoard(std::set<Cell>& board) override;
    bool PlacementFilter(Piece const& aspect, Cell const& pos) override;

};


class Pentominoes5x12 : public Pentominoes
{
protected:

    void BuildBoard(std::set<Cell>& board) override;
    bool AspectFilter(Piece const& piece, int flip, int rot) override;

};


class Pentominoes4x15 : public Pentominoes
{
protected:

    void BuildBoard(std::set<Cell>& board) override;
    bool AspectFilter(Piece const& piece, int flip, int rot) override;

};


class Pentominoes3x20 : public Pentominoes
{
protected:

    void BuildBoard(std::set<Cell>& board) override;
    bool AspectFilter(Piece const& piece, int flip, int rot) override;

};

#endif // !defined(POLYOS_H)
