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
	myReadFile.open("Resource\\Map\\"+this->name+".txt");
	
	if (name=="BossMap1")
	{
		int a = 0; 

	}

	int row = this->nRows; 
	int col = this->nColumns; 


	int** arr2 = new int*[row];
	for (int j = 0; j < row; j++)
	{
		arr2[j] = new int[col];

		for (int i = 0; i < col; i++)
		{
			arr2[j][i] = 0;

		}


	}
	string s1; //store a line of file
	for (istreambuf_iterator<char, char_traits<char> > it(myReadFile.rdbuf());
		it != istreambuf_iterator<char, char_traits<char> >(); it++) {

		s1 += *it; //append at end of string
	}

	string s2 = "";
	int k = 0;
	int count = 0;
	for (int j = 0; j < row; j++)
	{

		for (int i = 0; ; i++)
		{
			if (s1[k + i] == '\n' || s1[k + i] == '\0')
			{
				k += (i + 1);
				count = 0;
				break;

			}
			if (s1[k + i] != ' '&&s1[k + i] != '\0')
			{

				s2 += s1[k + i];


			}
			else
			{
				int n = std::stoi(s2);
				//n enter  maparr 
				arr2[j][count++] = n;
				s2 = "";

			}

		}


	}

	arr = new int*[row];
	for (int j = 0; j < row; j++)
	{
		arr[j] = new int[col];

		for (int i = 0; i < col; i++)
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
	for (int row = getTileYTop(cam->getY()); row<= getTileYBottom(cam->getY() + (float)cam->getHeight());row++)
	{
		for (int col = getTileXLeft(cam->getX()); col <= getTileXRight(cam->getX() + (float)cam->getWidth()); col++)
		{
			//int index = col + row * nColumns;
			if (row==29)
			{
				int a =1; 
			}
			int index = this->arrmapInLayer[row][col];
			//	if( ppTileTmx[ index ] ->getID() == 0)
			//		continue;
	
			TileSet* tileSet = tileSets[getTileSet(ppTileTmx[col + row * this->nColumns]->getID())];


			int tileID = ppTileTmx[col + row * this->nColumns]->getID() - tileSet->firstGridID; // ex : 128th represent by 127 in the 1D array
			int tileIDinSet = tileID;
	
			//tileID = tileSet -> getCurrentID(tileID);
			if (tileID != -1)

			{
				tileIDinSet = tileID;
			}
			/*TileSet* tileSet = tileSets[0];
			int tileIDinSet =index;*/

			int colInSet = tileIDinSet % nColumnsOfTileset;
			int rowInSet = tileIDinSet / nColumnsOfTileset;
			int dx = tileSet->margin + (colInSet) * (tileSet->spacing + tileSet->tileWidth);
			int dy = tileSet->margin + (rowInSet) * (tileSet->spacing + tileSet->tileHeight);
			ppTileTmx[col + row * this->nColumns]->draw(tileSet->pTexture, 16, 16, dx, dy, cam);
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
	nColumns =this->nColumns;
	nRows = this->nRows;

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
			ppTileTmx[col + row * nColumns] = new TileTmx(col * TILE_SIZE, row * TILE_SIZE, id);
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