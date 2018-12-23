#pragma once
class FatTab
{
public:
	FatTab(const int& p_Size);
	virtual ~FatTab();
	void display();
	void findThatSquare();
	inline void setRandFactor(int rand) { m_iRandFactor = rand; }

private : 
	void generateTab(const int& p_Size);
	bool isCorrupt(const int& p_line, const int& p_column, const int& size) const;
	int maxWithout0(const int& p_line, const int& p_column) const;
	int m_iRandFactor;
	std::vector<std::vector<char>> m_vTab;
	void enlightSquare(const int& p_line, const int& p_column, const int& size);

};

