#include "DeleteSmallArea.h"
#include "Regionprops.h"
#include "NewBlobLabel8.h"

// ɾ��С�������
int DeleteSmallArea(BYTE*imbw, int imWidth, int imHeight, int areaThresh)
{
	// ��ͨ������
	INT blobcount = 0;
	INT *bloblables = new INT[imWidth*imHeight];
	memset(bloblables,0,sizeof(INT)*imWidth*imHeight);
	NewBlobsLabel8(imbw,imWidth,imHeight,blobcount,bloblables);
	// ���
	INT *Area = new INT[blobcount];
	memset(Area,0,sizeof(INT)*blobcount);
	region_area(bloblables,blobcount,imWidth,imHeight,Area);
	// ��Ӿ���
	box *boundingbox = new box[blobcount];
	memset(boundingbox,0,sizeof(box)*blobcount);
	region_boundingbox(bloblables,blobcount,imWidth,imHeight,boundingbox);

	int maintainArea = blobcount;

	// ѭ��ȥ��С���
	for (int k = 0; k < blobcount; ++k)
	{
		if (Area[k] < areaThresh)
		{
			maintainArea--;
			INT top = boundingbox[k].row;
			INT left = boundingbox[k].col;
			INT width = boundingbox[k].width;
			INT height =boundingbox[k].height;
			INT bottom = top + height;
			INT right = left + width;
			for (int i = top; i < bottom; ++i)
			{
				for (int j = left; j < right; ++j)
				{
					if (bloblables[i*imWidth+j] == k+1)
					{
						imbw[i*imWidth+j] = 0;
					}
				}
			}
		}
	}
	delete [] bloblables;
	delete [] Area;
	delete [] boundingbox;
	return maintainArea;
}

// ɾ�������ϵ��������
int DeleteArea(BYTE*imbw, int imWidth, int imHeight, int lowThresh, int highThresh)
{
	// ��ͨ������
	INT blobcount = 0;
	INT *bloblables = new INT[imWidth*imHeight];
	memset(bloblables, 0, sizeof(INT)*imWidth*imHeight);
	NewBlobsLabel8(imbw, imWidth, imHeight, blobcount, bloblables);
	// ���
	INT *Area = new INT[blobcount];
	memset(Area, 0, sizeof(INT)*blobcount);
	region_area(bloblables, blobcount, imWidth, imHeight, Area);
	// ��Ӿ���
	box *boundingbox = new box[blobcount];
	memset(boundingbox, 0, sizeof(box)*blobcount);
	region_boundingbox(bloblables, blobcount, imWidth, imHeight, boundingbox);

	int maintainArea = blobcount;

	// ѭ��ȥ��С���
	for (int k = 0; k < blobcount; ++k)
	{
		if (Area[k] < lowThresh || Area[k] > highThresh)
		{
			maintainArea--;
			INT top = boundingbox[k].row;
			INT left = boundingbox[k].col;
			INT width = boundingbox[k].width;
			INT height = boundingbox[k].height;
			INT bottom = top + height;
			INT right = left + width;
			for (int i = top; i < bottom; ++i)
			{
				for (int j = left; j < right; ++j)
				{
					if (bloblables[i*imWidth + j] == k + 1)
					{
						imbw[i*imWidth + j] = 0;
					}
				}
			}
		}
	}
	delete[] bloblables;
	delete[] Area;
	delete[] boundingbox;
	return maintainArea;
}