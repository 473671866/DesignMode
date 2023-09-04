#include <iostream>
#include <string>
#include <vector>

//黑子，白子
enum Color
{
	WHITE,
	BLACK
};

//位置
class Pos
{
public:
	int m_x;
	int m_y;
	Pos(int x, int y) :m_x(x), m_y(y) {}
};

//棋子
class Piece
{
protected:
	Color m_color;

public:
	Piece(Color c) :m_color(c) {}

	virtual void draw() {}
};

//黑
class BlackPiece :public Piece
{
public:
	BlackPiece(Color c) :Piece(c) {}

	void draw()
	{
		std::cout << "black" << std::endl;
	}
};

//白
class WhitePiece :public Piece
{
public:
	WhitePiece(Color c) :Piece(c) {}

	void draw()
	{
		std::cout << "whtie" << std::endl;
	}
};

//棋盘
class PieceBoard
{
protected:
	std::vector<Pos*> m_piece;
	std::string m_black_name;
	std::string m_white_name;
	Piece* m_balck_piece;
	Piece* m_white_piece;

public:
	PieceBoard(std::string black, std::string whtie) :m_black_name(black), m_white_name(whtie)
	{
		this->m_balck_piece = nullptr;
		this->m_white_piece = nullptr;
	}

	void set_piece(Color c, Pos p)
	{
		if (c == BLACK)
		{
			if (this->m_balck_piece == nullptr)
			{
				this->m_balck_piece = new BlackPiece(c);
			}
			std::cout << p.m_x << " " << p.m_y << std::endl;
			this->m_balck_piece->draw();
		}
		else
		{
			if (this->m_white_piece == nullptr)
			{
				this->m_white_piece = new WhitePiece(c);
			}
			std::cout << p.m_x << " " << p.m_y << std::endl;
			this->m_white_piece->draw();
		}
		m_piece.push_back(&p);
	}
};

int main()
{
	PieceBoard* p = new PieceBoard("a", "b");
	p->set_piece(BLACK, Pos(1, 2));
	p->set_piece(WHITE, Pos(5, 3));
	system("pause");
	return 0;
}