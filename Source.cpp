#include <iostream>
#include <string>

using namespace std;


class Box
{

private:

	int v = 0;
	int weight = 0;
	int pr = 0;

public:

	Box()
	{

	}

	Box(int weight, int v, int pr)
	{
		this->weight = weight;
		this->v = v;
		this->pr = pr;

	}

	int GetV()
	{
		return v;
	}

	int GetWeight()
	{
		return weight;
	}

	int GetPr()
	{
		return pr;
	}

};

class PaperBox : public Box
{
public:

	PaperBox(int weight, int v, int pr) : Box(weight, v, pr)
	{

	}

private:


};

class Thing
{

private:

	int v2 = 0;
	int weight2 = 0;
	int k = 0;

public:

	Thing()
	{

	}

	Thing(int weight2, int v2, int k)
	{
		this->weight2 = weight2;
		this->v2 = v2;
		this->k = k;
	}

	int GetV2()
	{
		return v2;
	}

	int GetWeight2()
	{
		return weight2;
	}

	int GetK()
	{
		return k;
	}

};

class Rice : public Thing
{
public:

	Rice(int weight2, int v2, int k) : Thing(weight2, v2, k)
	{

	}

private:


};

class Pasta : public Rice
{
public:

	Pasta(int weight2, int v2, int k) : Rice(weight2, v2, k)
	{

	}

private:

};


int Count(PaperBox& paperbox, Rice& rice, Pasta& pasta, int& count1, int& count2)
{

	int vb = paperbox.GetV();
	int weightb = paperbox.GetWeight();
	int sum = 0;

	while (true)
	{

		if (vb >= rice.GetV2() && weightb >= rice.GetWeight2())
		{
			count1++;
			vb -= rice.GetV2();
			weightb -= rice.GetWeight2();
			sum += rice.GetK();
		}
		if (vb >= pasta.GetV2() && weightb >= pasta.GetWeight2())
		{
			count2++;
			vb -= pasta.GetV2();
			weightb -= pasta.GetWeight2();
			sum += pasta.GetK();
		}
		else
		{
			break;
		}
		if (paperbox.GetPr() < sum)
		{
			cout << "Коробка не выдержала!" << endl;
			break;
		}


	}

	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	int count1 = 0;
	int count2 = 0;

	PaperBox paperbox(2500, 1400, 10);

	Rice rice(900, 300, 2);

	Pasta pasta(450, 400, 3);

	Count(paperbox, rice, pasta, count1, count2);

	cout << "Вместилось " << count1 << " единиц(а) риса" << endl;
	cout << "Вместилось " << count2 << " единиц(а) макарон" << endl;

	return 0;
}