#include "stdafx.h"
#include "FatTab.h"


FatTab::FatTab(const int& p_Size)
{
	srand(time(NULL));
	m_iRandFactor = 99; // default random factor
	generateTab(p_Size);
}


FatTab::~FatTab()
{
}

void FatTab::generateTab(const int& p_Size)
{
	int l_iRandom;
	for (int col = 0; col < p_Size; col++)
	{
		std::vector<char> line;
		for (int index = 0; index < p_Size; index++)
		{
			l_iRandom = rand() % 100 + 1;
			if (l_iRandom > m_iRandFactor) // randFactor applied
			{
				line.push_back('0');
			}
			else {
				line.push_back('.');
			}
		}
		m_vTab.push_back(line);
	}
}

void FatTab::display()
{
	for (int line = 0; line < m_vTab.size(); line++)
	{
		for (int col = 0; col < m_vTab.size(); col++)
		{
			std::cout << m_vTab[line][col] << " ";
		}
		std::cout << std::endl;
	}
}

void FatTab::findThatSquare()
{
	int l_iMax = -1;
	int l_iColumn = -1;
	int l_iLine = -1;

	for (int line = 0; line < m_vTab.size(); line++)
	{
		for (int col = 0; col < m_vTab.size(); col++)
		{
			int max = maxWithout0(line, col);

			if ( max > l_iMax && !isCorrupt(line, col, max))
			{
				l_iLine = line;
				l_iColumn = col;
				l_iMax = max;
			}
		}
	}
	std::cout << " Line : " << l_iLine << " Column : " << l_iColumn << " Size : " << l_iMax << std::endl;
	enlightSquare(l_iLine, l_iColumn, l_iMax);
}

void FatTab::findThatSquareBetter()
{
	int l_iMax = 1;
	int l_iColumn = -1;
	int l_iLine = -1;

	for (int line = 0; line < m_vTab.size(); line++)
	{
		if (m_vTab[line].size() - line < l_iMax)
		{
			std::cout << " Better /// Line : " << l_iLine << " Column : " << l_iColumn << " Size : " << l_iMax << std::endl;
			enlightSquare(l_iLine, l_iColumn, l_iMax);
			return;
		}

		for (int col = 0; col < m_vTab.size(); col++)
		{
			bool flagContinue = true;
			int l_max = l_iMax +1;
			for (int max = l_max; flagContinue; max++)
			{
				if (isCorrupt(line, col, max)) flagContinue = false;
				else {
					l_iLine = line;
					l_iColumn = col;
					l_iMax = max;
				}
			}
		}
		
	}

	std::cout << " Better // Line : " << l_iLine << " Column : " << l_iColumn << " Size : " << l_iMax << std::endl;
	enlightSquare(l_iLine, l_iColumn, l_iMax);
}

bool FatTab::isCorrupt(const int& p_line, const int& p_column, const int& size) const
{
	if (size > (m_vTab[p_line].size() - p_line) || size > (m_vTab[p_line].size() - p_column)) return true;

	for (int line = p_line ; line < p_line + size; line++)
	{
		for (int col = p_column ; col < p_column + size; col++)
		{
			if (m_vTab[line][col] == '0') return true;
		}
	}

	return false;
}

int FatTab::maxWithout0(const int& p_line, const int& p_column) const
{
	int maxLine = -1;
	int maxColumn = -1;
	bool flagContinue = true;

	// max column
	for (int column = p_column; flagContinue && column < m_vTab[p_line].size(); column++)
	{
		if (m_vTab[p_line][column] == '0') 
		{
			maxColumn = column - p_column;
			flagContinue = false;
		}
	}

	if (flagContinue)
	{
		maxColumn = m_vTab[p_line].size() - 1 - p_column;
	}
	else {
		flagContinue = true;
	}

	// max Line
	for (int line = p_line; flagContinue && line < m_vTab[p_line].size(); line++)
	{
		if (m_vTab[line][p_column] == '0')
		{
			maxLine = line - p_line;
			flagContinue = false;
		}
	}

	if (flagContinue)
	{
		maxLine = m_vTab[p_line].size() - 1 - p_line;
	}

	// compare 
	if (maxLine < maxColumn) return maxLine;
	else return maxColumn;
}

void FatTab::enlightSquare(const int& p_line, const int& p_column, const int& size)
{
	for (int line = p_line; line < p_line + size; line++)
	{
		for (int col = p_column; col < p_column + size; col++)
		{
			m_vTab[line][col] = 'X';
		}
	}
}
