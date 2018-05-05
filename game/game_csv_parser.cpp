//	Copyright (C) 2018 Streanga Sarmis-Stefan<streangasarmis@gmail.com>
//
//	This program is free software : you can redistribute it and / or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program, if not, see <http://www.gnu.org/licenses/>.

#include "game_csv_parser.hpp"

void CSVParser::clearData(Data& data) {
	delete[] data.values;
}

CSVParser::Data CSVParser::parseFileToData(const char* path) {
	Data result;
	result.width = 0;
	result.height = 0;
	std::ifstream file;
	file.open(path, std::ios::binary | std::ios::ate);

	int size = file.tellg();
	result.values = new char[size + 1];
	file.clear();
	file.seekg(0, std::ios::beg);

	unsigned i = 0;	
	unsigned columnCount = 0;
	unsigned rowCount = 0;
	char remember = 0;
	bool carry = false;
	char c;

	while (file.get(c)) {
		if (c == '\r') {
			continue;
		}

		if (c == '\n') {
			++rowCount;
			result.values[i++] = remember;
			remember = 0;
			if (result.width == 0) {
				result.width = columnCount;
			}
			continue;
		}

		if (c == ',') {
			if (carry) {
				carry = !carry;
			}
			result.values[i++] = remember;
			remember = 0;
			continue;
		}

		if (c != ' ') {
			if (c == '-') {
				carry = true;
				continue;
			}

			c -= '0';
			
			if (carry) {
				carry = !carry;
				c *= -1;
			}
			
			if (result.width == 0) {
				++columnCount;
			}

			if (remember != 0) {
				remember *= 10;
				remember += c;
			} else {
				remember = c;
			}

		}
	}
	result.height = rowCount;
	result.values[size] = '\0';
	file.close();
	return result;
}