//#include<SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//#include <climits>
//#include <algorithm>
//#include <functional>
//#include <string>
//#include <sstream>
//#include <queue>
//
//using namespace std;
//using namespace sf;
//
//template <class T>
//class Graph
//{
//private:
//	vector<T> vertexList;
//	vector<vector<int>> adjMatrix;
//	int maxSize;
//	queue<T> VertsQueue;
//	vector<int> labelList;
//public:
//	Graph(const int& size);
//	Graph() : Graph(7) {};
//	void showAdj();
//	bool isEmpty();
//	bool isFull();
//	int GetVertPos(const T&);
//	int GetAmountVerts();
//	void insertVertex(const T& ver);
//	int GetAmountEdges();
//	int GetWeight(const T&, const T&);
//	void InsertEdge(const T& vertex1, const T& vertex2, int weight = 1);
//	std::vector<T> GetNbrs(const T&);
//	void Print();
//	void Dijkstra(T& startVertex);
//	bool AllVisited(vector<bool>& visitedVerts);
//	void FillLabels(T& startVertex);
//	void Draw();
//};
//template<class T>
//inline void Graph<T>::Draw()
//{
//	const float pi = 3.14159f;
//	const int Width = 800;
//	const int Height = 600;
//	RenderWindow window(VideoMode(Width, Height), "My window", Style::Close);
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//		}
//		window.clear(Color::White);
//		CircleShape circle(200.f);
//		circle.setFillColor(sf::Color(100, 250, 50));
//		circle.setRadius(40.f);
//		circle.setPointCount(100);
//		circle.setOrigin(40.f, 40.f);
//		circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
//		Font font;
//		font.loadFromFile("timesnewromanpsmt.ttf");
//		Text text;
//		text.setFont(font);
//		text.setCharacterSize(100);
//		text.setFillColor(Color::Red);
//		vector<CircleShape> circles;
//		vector<Text> textes;
//		vector<Text> edges;
//		text.setCharacterSize(20);
//		for (int i = 0; i < maxSize; i++)
//		{
//			text.setString(vertexList[i]);
//			FloatRect textRect = text.getLocalBounds();
//			text.setOrigin(textRect.left + textRect.width / 2.0f,
//				textRect.top + textRect.height / 2.0f);
//			text.setPosition(window.getSize().x / 2 + 160 * cos(i*2 * 3.14 / maxSize), window.getSize().y / 2 + 160 * sin(i*2 * 3.14 / maxSize));
//			circle.setPosition(window.getSize().x / 2 + 160 * cos(i*2 * 3.14 / maxSize), window.getSize().y / 2 + 160 * sin(i* 2 * 3.14 / maxSize));
//			circles.push_back(circle);
//			textes.push_back(text);
//		}
//		for (int i = 0; i < maxSize; i++)
//			for (int j = 0; j < maxSize; j++)
//				if (adjMatrix[i][j] != 0)
//				{
//					Vertex line[] =
//					{
//						Vertex(Vector2f(circles[i].getPosition().x, circles[i].getPosition().y)),
//						Vertex(Vector2f(circles[j].getPosition().x, circles[j].getPosition().y))
//					};
//					window.draw(line, 2, Lines);
//					text.setString(to_string(adjMatrix[i][j]));
//					FloatRect textRect = text.getLocalBounds();
//					text.setOrigin(textRect.left + textRect.width / 2.0f,
//						textRect.top + textRect.height / 2.0f);
//					text.setPosition((circles[i].getPosition().x + circles[j].getPosition().x) / 2, (circles[i].getPosition().y + circles[j].getPosition().y) / 2);
//					edges.push_back(text);
//				}
//		for (int i = 0; i < edges.size(); i++)
//		{
//			window.draw(edges[i]);
//		}
//		for (int i = 0; i < maxSize; i++)
//		{
//			window.draw(circles[i]);
//			window.draw(textes[i]);
//		}
//		window.display();
//	}
//}
//template <class T>
//void Graph<T>::FillLabels(T& startVertex)
//{
//	for (int i = 0, size = vertexList.size(); i < size; ++i)
//		labelList[i] = 1000000;
//	int pos = GetVertPos(startVertex);
//	labelList[pos] = 0;
//};
//
//template <class T>
//bool Graph<T>::AllVisited(vector<bool>& visitedVerts)
//{
//	//Проверяет, все ли ноды были посещены
//	bool flag = true;
//	for (int i = 0; i < this->vertexList.size(); i++)
//		if (visitedVerts[i] != true)
//			flag = false;
//	return flag;
//};
//
//template <class T>
//void Graph<T>::Dijkstra(T& startVertex)
//{
//	for (int i = 0; i < vertexList.size(); i++)
//		for (int j = 0; j < vertexList.size(); j++)
//			if (adjMatrix[i][j] < 0)
//				return;
//
//	if (GetVertPos(startVertex) == -1)
//		return;
//
//	vector<bool> visitedVerts(vertexList.size());
//	fill(visitedVerts.begin(), visitedVerts.end(), false);
//
//	this->FillLabels(startVertex);
//	T curSrc = startVertex;
//	vector<T> neighbors;
//
//	while (!this->AllVisited(visitedVerts))
//	{
//		neighbors = this->GetNbrs(curSrc);
//		int startLabel = labelList[GetVertPos(curSrc)];
//		T* minNeighbor_ptr = nullptr;
//		int minW = 1000;
//
//		for (int i = 0; i < neighbors.size(); ++i)
//		{
//			int weight = this->GetWeight(curSrc, neighbors[i]);
//			int nIndex = this->GetVertPos(neighbors[i]);
//			int nextLabel = labelList[nIndex];
//			if (startLabel + weight < nextLabel)
//			{
//				labelList[nIndex] = startLabel + weight;
//			};
//			if (!visitedVerts[nIndex] && minW > labelList[nIndex])
//			{
//				minW = labelList[nIndex];
//				minNeighbor_ptr = &neighbors[i];
//			};
//		};
//		visitedVerts[GetVertPos(curSrc)] = true;
//		if (minNeighbor_ptr != nullptr)
//		{
//			curSrc = *minNeighbor_ptr;
//		};
//	};
//	for (int i = 0; i < GetVertPos(startVertex); ++i)
//	{
//		cout << "Кратчайшее расстояние от вершины " << startVertex
//			<< " до вершины " << vertexList[i] << " равно "
//			<< labelList[GetVertPos(vertexList[i])] << endl;
//	};
//
//	for (int i = GetVertPos(startVertex) + 1; i < vertexList.size(); ++i)
//	{
//		cout << "Кратчайшее расстояние от вершины " << startVertex
//			<< " до вершины " << vertexList[i] << " равно "
//			<< labelList[GetVertPos(vertexList[i])] << endl;
//	};
//
//};
//
//
//
//template<class T>
//inline Graph<T>::Graph(const int& size)
//{
//	this->labelList = vector<int>(size);
//	this->maxSize = size;
//	this->adjMatrix = vector<vector<int>>(size, vector<int>(size));
//	for (int i = 0; i < this->maxSize; ++i)
//	{
//		for (int j = 0; j < this->maxSize; ++j)
//		{
//			this->adjMatrix[i][j] = 0;
//		};
//	};
//};
//
//template<class T>
//inline void Graph<T>::showAdj()
//{
//	for (int i = 0; i < this->maxSize; ++i)
//	{
//		for (int j = 0; j < this->maxSize; ++j)
//		{
//			cout << this->adjMatrix[i][j] << ' ';
//		};
//		cout << endl;
//	}
//};
//
//template<class T>
//inline bool Graph<T>::isEmpty()
//{
//	return this->vertexList.size() == 0;
//};
//
//
//
//
//template<class T>
//inline bool Graph<T>::isFull()
//{
//	return this->vertexList.size() == this->maxSize;
//};
//
//template<class T>
//inline int Graph<T>::GetVertPos(const T& v)
//{
//	for (int i = 0; i < this->vertexList.size(); ++i)
//	{
//		if (this->vertexList[i] == v)
//		{
//			return i;
//		}
//	}
//	return -1;
//};
//
//template<class T>
//inline int Graph<T>::GetAmountVerts()
//{
//	return this->vertexList.size();
//};
//
//template<class T>
//inline void Graph<T>::insertVertex(const T& vert)
//{
//	if (this->isFull())
//	{
//		cout << "Невозможно добавить вершину." << endl;
//		return;
//	};
//	this->vertexList.push_back(vert);
//};
//
//template<class T>
//int Graph<T>::GetAmountEdges()
//{
//	int amount = 0;
//	if (!this->IsEmpty())
//	{
//		for (int i = 0; i < this->vertexList.size(); ++i)
//		{
//			for (int j = 0; j < this->vertexList.size(); ++j)
//			{
//				if (this->adjMatrix[i][j] != 0)
//				{
//					amount++;
//				}
//			}
//		}
//	}
//	return amount;
//};
//
//template<class T>
//inline int Graph<T>::GetWeight(const T& v1, const T& v2)
//{
//	if (this->isEmpty())
//	{
//		return 0;
//	};
//
//	int v1_p = this->GetVertPos(v1);
//	int v2_p = this->GetVertPos(v2);
//
//	if (v1_p == -1 || v2_p == -1)
//	{
//		cout << "Одного из узлов в графе не существует." << endl;
//		return 0;
//	};
//
//	return this->adjMatrix[v1_p][v2_p];
//};
//template<class T>
//std::vector<T> Graph<T>::GetNbrs(const T& vertex) {
//	std::vector<T> nbrsList;
//	int pos = this->GetVertPos(vertex);
//	if (pos != -1)
//	{
//		for (int i = 0; i < this->vertexList.size(); ++i)
//		{
//			if (this->adjMatrix[pos][i] != 0)
//			{
//				nbrsList.push_back(this->vertexList[i]);
//			}
//		}
//	}
//	return nbrsList;
//};
//
//template<class T>
//void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight) {
//	if (GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
//		int vertPos1 = GetVertPos(vertex1);
//		int vertPos2 = GetVertPos(vertex2);
//
//		if (this->adjMatrix[vertPos1][vertPos2] != 0)
//		{
//			cout << "Ребро между вершинами уже есть" << endl;
//			return;
//		}
//		else
//		{
//			this->adjMatrix[vertPos1][vertPos2] = weight;
//			this->adjMatrix[vertPos2][vertPos1] = weight;
//		}
//	}
//	else
//	{
//		cout << "Как минимум 1 вершини не хватает нет в графе " << endl;
//		return;
//	}
//};
//
//template<class T>
//void Graph<T>::Print() {
//	if (!this->isEmpty())
//	{
//		cout << "Матрица смежности графа: " << endl;
//
//		cout << "-  ";
//		for (int i = 0; i < vertexList.size(); ++i)
//		{
//			cout << vertexList[i] << "  ";
//		}
//		cout << endl;
//
//		for (int i = 0; i < this->vertexList.size(); ++i)
//		{
//			cout << this->vertexList[i] << " ";
//			for (int j = 0; j < this->vertexList.size(); ++j)
//			{
//				cout << " " << this->adjMatrix[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	else {
//		cout << "Граф пуст " << endl;
//	}
//}
//
//int main()
//{
//	int E;
//	setlocale(LC_ALL, "Russian");
//	cout << " количество граф: "; cin >> E; cout << endl;
//	Graph<string> p(E);
//	p.showAdj();
//	int V, ves; string ver, source, target;
//	cout << " колическто вершин: "; cin >> V; cout << endl;
//
//	for (int i = 0; i < V; ++i)
//	{
//		cout << " вершина: "; cin >> ver;
//		p.insertVertex(ver);
//		cout << endl;
//	}
//
//	for (int i = 0; i < E; ++i)
//	{
//		cout << " Исходная: "; cin >> source; cout << endl;
//		cout << " конечная: "; cin >> target; cout << endl;
//		cout << " Вес: "; cin >> ves;
//
//		//string* targetVertPtr = &target;
//		p.InsertEdge(source, target, ves);
//	}
//	cout << endl;
//	//string kl = "1";
//
//	p.Draw();
//
//	p.Print();
//	cout << " вершина: "; cin >> ver;
//	int h = 100, w = 100, h1 = 100, w1 = 100;
//	//vector<int> vertexList;
//	//vector<vector<int>> adjMatrix(maxSize, vector<int>(maxSize, 10));
//}
