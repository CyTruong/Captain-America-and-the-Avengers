#include "TileLayer.h"
#include <fstream>
#include<sstream>
#include<string>

TileLayer::TileLayer(int tileSize, int nColumns, int nRows, std::string name, std::vector < TileSet* > & tileSets)
	:
	Layer(tileSize, nColumns, nRows, name, tileSets)
{

}


int TileLayer::getTileXLeft(float x)
{
	return x / tileSize;
}
int TileLayer::getTileXRight(float x)
{
	int ix = x / tileSize;
	if (ix * tileSize == x)
		ix--;
	return ix;
}
int TileLayer::getTileYTop(float y)
{
	return y / 16;
}
int TileLayer::getTileYBottom(float y)
{

	int iy = y / 16;
	if (iy * 16 == y)
		iy--;
	return iy;
}
TileTmx* TileLayer::getTileTmx(int ix, int iy)
{
	return ppTileTmx[ix + iy * nColumns];
}

void TileLayer::fromfile(int **&arr)
{
	ifstream myReadFile;
	myReadFile.open("Resource\\Map\\captainAmerica.txt");



	int arr2[30][128];

	string s1; //store a line of file
	for (istreambuf_iterator<char, char_traits<char> > it(myReadFile.rdbuf());
		it != istreambuf_iterator<char, char_traits<char> >(); it++) {

		s1 += *it; //append at end of string
	}

	string s2 = "";
	int k = 0;
	int count = 0;
	for (int j = 0; j < 30; j++)
	{
		if (j == 1)
		{
			int a = 1;
		}

		for (int i = 0; ; i++)
		{
			if (s1[k + i] == '\n' || s1[k + i] == '\0')
			{
				k += (i + 1);
				count = 0;

				if (i == 15)
				{
					int a = 1;
				}
				break;

			}
			if (s1[k + i] != ' ')
			{

				s2 += s1[k + i];


			}
			else
			{
				int n = std::stoi(s2);

				int *a = &n;

				//n enter  maparr 
				arr2[j][count++] = n;




				s2 = "";

			}

		}


	}

	arr = new int*[30];
	for (int j = 0; j < 30; j++)
	{
		arr[j] = new int[128];

		for (int i = 0; i < 128; i++)
		{
			arr[j][i] = arr2[j][i];

		}


	}

	arrmapInLayer = arr;

	myReadFile.close();





	// sau đó lấy chuỗi đó tách ra thành chuỗi con rồi add vào mảng 

	// chuyển vào mảng id (map )





}


// changemap  . pptiletmx 

void TileLayer::draw(Camera* cam)
{
	for (int row = 0; row < 30; row++)
	{
		for (int col = getTileXLeft(cam->getX()); col <= getTileXRight(cam->getX() + (float)cam->getWidth()); col++)
		{
			//int index = col + row * nColumns;
			int index = this->arrmapInLayer[row][col];
			//	if( ppTileTmx[ index ] ->getID() == 0)
			//		continue;
			if (row == 9 && col == 4)
			{
				int a = 0;

			}
			TileSet* tileSet = tileSets[getTileSet(ppTileTmx[col + row * 128]->getID())];


			int tileID = ppTileTmx[col + row * 128]->getID() - tileSet->firstGridID; // ex : 128th represent by 127 in the 1D array
			int tileIDinSet = tileID;
			if (tileID == 128 * 28 + 1)
			{
				int a = 1;
			}
			//tileID = tileSet -> getCurrentID(tileID);
			if (tileID != -1)

			{
				tileIDinSet = tileID;
			}
			/*TileSet* tileSet = tileSets[0];
			int tileIDinSet =index;*/

			int colInSet = tileIDinSet % 16;
			int rowInSet = tileIDinSet / 16;
			int dx = tileSet->margin + (colInSet) * (tileSet->spacing + tileSet->tileWidth);
			int dy = tileSet->margin + (rowInSet) * (tileSet->spacing + tileSet->tileHeight);
			ppTileTmx[col + row * 128]->draw(tileSet->pTexture, 16, 16, dx, dy, cam);
		}

	}





	//	int index = this->arrmapInLayer[y][x]; 



		//int yoffset = 0; 

		//if (index> 64-1 )
		//{
		//	yoffset++; 
		//	index = index - 64; 

		//	TileSet* tileSet = tileSets[getTileSet(ppTileTmx[index]->getID())];
		//	int tileID = ppTileTmx[index]->getID()+1 - tileSet->firstGridID; // ex : 128th represent by 127 in the 1D array
		//	int tileIDinSet = tileID;

		//	tileID = tileSet->getCurrentID(tileID);
		//	if (tileID != -1)

		//	{
		//		tileIDinSet = tileID;
		//	}


		//	int colInSet = tileIDinSet % 16;
		//	int rowInSet = tileIDinSet / 16;
		//	int dx = tileSet->margin + (colInSet) * (tileSet->spacing + tileSet->tileWidth);
		//	int dy = tileSet->margin + (rowInSet) * (tileSet->spacing + tileSet->tileHeight);
		//	ppTileTmx[index ] -> draw( tileSet ->pTexture, 16, 20,dx, dy, cam);

		//}



}


void TileLayer::setTileIDs(std::vector< std::vector< int> > tileIDs)
{
	this->tileIDs = tileIDs;
}
void TileLayer::createTileTmx()
{
	nColumns = 128;
	nRows = 30;

	ppTileTmx = new TileTmx*[nColumns * nRows];

	for (int row = 0; row < nRows; row++)
	{
		for (int col = 0; col < nColumns; col++)
		{
			if (row == 9 && col == 4)
			{
				int a = 1;

			}
			int id = tileIDs[row][col];
			ppTileTmx[col + row * nColumns] = new TileTmx(col * 16, row * 16, id);
		}
	}
}
int TileLayer::getTileSet(int id)
{
	for (int i = 0; i < tileSets.size(); i++)
	{
		if (id >= tileSets[i]->firstGridID && id <= tileSets[i]->lastGridID)
		{
			return i;
		}

	}


}