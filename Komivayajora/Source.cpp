#include <iostream>
#include<SFML/Graphics.hpp>
#include <locale>
#include <clocale>
#include <climits>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>


using namespace sf;
using namespace std;

template <class T>
class Graph
{
public:
    vector<T> List_of_vertexes;
    vector<vector<int>> Matrix;
    int maxSize;
    queue<T> QVrt;
    vector<int> Labels_list;
    int rec = INT_MAX;
    list<int> Pathes;
public:
    Graph(const int& size);
    Graph() : Graph(10) {};
    void ShowM();
    void insertVertex(const T& ver);
    void InsertEdge(const T& vertex1, const T& vertex2, int weight = 1);
    int GetVertPos(const T&);
    int GetCountVerts();
    int GetCountLines();
    int GetWeight(const T&, const T&);
    bool Emptiness();
    bool FullTub();
    vector<T> GetINFO(const T&);
    void Print();
    void DXTRA(T& startVertex);
    void Put_inLbls(T& startVertex);
    void DRAW();
    void ADD(const T& ver, int val);
    void DELETEVRTX(T& ver);
    void DELETEE(const T& vertex1, const T& vertex2);
    bool vse_visited(vector<bool>& visitedVerts);
    vector<int> getINFO(const int& vert);
    void focus(const int& start, const int& current, list<int>& path, vector<bool>& visitedVerts);
    void hz(const int& start);
};
template<class T>
void Graph<T>::hz(const int& start)
{
    list<int> Pathes;
    Pathes.push_back(start);
    vector<bool> visit(this->List_of_vertexes.size(), false);
    visit[start] = true;
    this->focus(start, start, Pathes, visit);
}
template<class T>
vector<int> Graph<T>::getINFO(const int& vert)
{
    list<int> resolution;

    for (int j = 0; j < this->List_of_vertexes.size(); ++j)
    {
        if (this->Matrix[vert][j])
            resolution.push_back(j);
    }



    return vector<int>(resolution.begin(), resolution.end());
}
template<class T>
void Graph<T>::focus(const int& start, const int& current, list<int>& path, vector<bool>& visitedVerts)
{
    if (this->vse_visited(visitedVerts))
    {
        int min = 0;
        if (!this->Matrix[current][start])
        {
            return;
        }


        vector<int> p(path.begin(), path.end());
        for (int i = 0; i < p.size() - 1; ++i)
        {
            min += this->Matrix[p[i]][p[i + 1]];
        }
        min += this->Matrix[current][start];
        cout << endl;
        if (rec > min)
        {
            rec = min;
            this->Pathes = path;
        }

        cout << endl;
    }

    vector<int> info = this->getINFO(current);

    for (int& i : info)
    {
        if (!visitedVerts[i])
        {
            vector<bool> cpy_vis(visitedVerts.begin(), visitedVerts.end());
            list<int> path_cpy(path.begin(), path.end());
            cpy_vis[i] = true;
            path_cpy.push_back(i);
            focus(start, i, path_cpy, cpy_vis);
        }
    };

};
template<class T>
inline void Graph<T>::ADD(const T& ver, int val)
{
    this->maxSize = val;
    this->List_of_vertexes.push_back(ver);
};
template<class T>
inline void Graph<T>::DELETEVRTX(T& ver)
{
    if (maxSize == 0 || GetVertPos(ver) == -1)
    {
        cout << "!!! Невозможно удалить вершину !!!" << endl;
        return;
    }
    for (int j = 0; j < List_of_vertexes.size(); ++j)
        if (List_of_vertexes[j] == ver)
        {
            maxSize--;
            List_of_vertexes.erase(List_of_vertexes.begin() + j);
            Matrix.erase(Matrix.begin() + j);
            for (int i = 0; i < Matrix.size(); i++)
                Matrix[i].erase(Matrix[i].begin() + j);
        }
}
template<class T>
void Graph<T>::DELETEE(const T& vertex1, const T& vertex2) {
    if (GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
        int Vert_Pos_1 = GetVertPos(vertex1);
        int Vert_Pos_2 = GetVertPos(vertex2);
        this->Matrix[Vert_Pos_1][Vert_Pos_2] = 0;
        this->Matrix[Vert_Pos_2][Vert_Pos_1] = 0;
    }
    else
    {
        cout << "Не хватает минимум одной вершины!!" << endl;
        return;
    }
};
float X = 0, Y = 0; bool Moving = false;
template<class T>
inline void Graph<T>::DRAW()
{
    const float pi = 3.14159f;
    bool f = false;
    RenderWindow window(VideoMode(1024, 960), "Набиев Саид РИС-21-1", Style::Close);
    while (window.isOpen())
    {
        Event event;
        window.clear(Color::Black);
        CircleShape circle(200.f);
        RectangleShape Add_Circle(Vector2f(220.f, 50.f));
        RectangleShape Add_Path(Vector2f(220.f, 50.f));
        RectangleShape Delete_Circle(Vector2f(220.f, 50.f));
        RectangleShape Delete_Path(Vector2f(220.f, 50.f));
        RectangleShape Find_Path(Vector2f(220.f, 50.f));
        Add_Circle.setPosition(800.f, 200.f);
        Add_Circle.setFillColor(Color(47, 79, 79));
        Add_Path.setPosition(800.f, 300.f);
        Add_Path.setFillColor(Color(47, 79, 79));
        Delete_Circle.setPosition(800.f, 400.f);
        Delete_Circle.setFillColor(Color(47, 79, 79));
        Delete_Path.setPosition(800.f, 500.f);
        Delete_Path.setFillColor(Color(47, 79, 79));
        Find_Path.setPosition(800.f, 600.f);
        Find_Path.setFillColor(Color(47, 79, 79));
        Vector2i mouse_pos = Mouse::getPosition(window);
        Font font;
        font.loadFromFile("timesnewromanpsmt.ttf");
        Text min_path_txt;
        min_path_txt.setPosition(10.f, 900.f);
        min_path_txt.setFont(font);
        min_path_txt.setFillColor(Color::White);
        min_path_txt.setCharacterSize(20);
        min_path_txt.setString("Минимальный путь: ");
        Text hmin_text;

        hmin_text.setPosition(200.f, 900.f);
        hmin_text.setFont(font);
        hmin_text.setFillColor(Color::White);
        hmin_text.setCharacterSize(20);
        window.draw(hmin_text);

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                    if (Add_Circle.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
                    {
                        string h; cout << endl;
                        cout << "Введите вершину -> ";
                        cin >> h;
                        this->ADD(h, (List_of_vertexes.size() + 1));
                        this->Print();
                    }
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                    if (Add_Path.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
                    {
                        string x, y;
                        int h;cout << endl;
                        cout << "Введите вершины и номер пути ->";
                        cin >> x >> y >> h;
                        this->InsertEdge(x, y, h);
                        this->Print();
                    }
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                    if (Delete_Circle.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
                    {
                        string ver; cout << endl;
                        cout << "Введите вершину для удаления -> ";
                        cin >> ver;
                        this->DELETEVRTX(ver);
                        this->Print();
                    }
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                    if (Find_Path.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
                    {
                        string ver; cout << endl;
                        cout << "Введите вершину с которой начнётся путь ->  ";
                        cin >> ver;
                        this->hz(this->GetVertPos(ver));
                        cout << this->rec << endl;
                        this->Print();
                        f = true;

                    }

            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                    if (Delete_Path.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
                    {
                        string x, y; cout << endl;
                        cout << "Введите пути, которые надо удалить ->";
                        cin >> x >> y;
                        this->DELETEE(x, y);
                        this->Print();
                    }
            }
        }

        Text name_text;
        name_text.setPosition(810.f, 210.f);
        name_text.setFont(font);
        name_text.setFillColor(Color::White);
        name_text.setCharacterSize(20);
        name_text.setString("Добавить вершину");

        Text name1_text;
        name1_text.setPosition(810.f, 310.f);
        name1_text.setFont(font);
        name1_text.setFillColor(Color::White);
        name1_text.setCharacterSize(20);
        name1_text.setString("Добавить путь");

        Text name2_text;
        name2_text.setPosition(810.f, 410.f);
        name2_text.setFont(font);
        name2_text.setFillColor(Color::White);
        name2_text.setCharacterSize(20);
        name2_text.setString("Удалить вершину");

        Text name3_text;
        name3_text.setPosition(810.f, 510.f);
        name3_text.setFont(font);
        name3_text.setFillColor(Color::White);
        name3_text.setCharacterSize(20);
        name3_text.setString("Удалить путь");

        Text name4_text;
        name4_text.setPosition(810.f, 610.f);
        name4_text.setFont(font);
        name4_text.setFillColor(Color::White);
        name4_text.setCharacterSize(20);
        name4_text.setString("Найти кратчайший путь");

        circle.setFillColor(sf::Color(0, 128, 128));
        circle.setRadius(40.f);
        circle.setPointCount(100);
        circle.setOrigin(40.f, 40.f);
        circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);

        Text text;
        text.setFont(font);
        text.setCharacterSize(100);
        text.setFillColor(Color::White);
        vector<CircleShape> circles;
        vector<Text> textes;
        vector<Text> edges;
        text.setCharacterSize(20);
        for (int i = 0; i < maxSize; i++)
        {
            double number_p = 3.14;
            text.setString(List_of_vertexes[i]);
            FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2.0f,
                textRect.top + textRect.height / 2.0f);
            text.setPosition(window.getSize().x / 2 + 160 * cos(i * 2 * number_p / maxSize), window.getSize().y / 2 + 160 * sin(i * 2 * number_p / maxSize));
            circle.setPosition(window.getSize().x / 2 + 160 * cos(i * 2 * number_p / maxSize), window.getSize().y / 2 + 160 * sin(i * 2 * number_p / maxSize));
            circles.push_back(circle);
            textes.push_back(text);
        }
        for (int i = 0; i < maxSize; i++)
            for (int j = 0; j < maxSize; j++)
                if (Matrix[i][j] != 0)
                {
                    Vertex line[] =
                    {
                        Vertex(Vector2f(circles[i].getPosition().x, circles[i].getPosition().y)),
                        Vertex(Vector2f(circles[j].getPosition().x, circles[j].getPosition().y))
                    };
                    window.draw(line, 2, Lines);
                    text.setString(to_string(Matrix[i][j]));
                    FloatRect textRect = text.getLocalBounds();
                    text.setOrigin(textRect.left + textRect.width / 2.0f,
                        textRect.top + textRect.height / 2.0f);
                    text.setPosition((circles[i].getPosition().x + circles[j].getPosition().x) / 2, (circles[i].getPosition().y + circles[j].getPosition().y) / 2);
                    edges.push_back(text);
                }
        for (int i = 0; i < edges.size(); i++)
        {
            window.draw(edges[i]);
        }
        for (int i = 0; i < maxSize; i++)
        {
            window.draw(circles[i]);
            window.draw(Add_Circle);
            window.draw(Add_Path);
            window.draw(Delete_Circle);
            window.draw(Delete_Path);
            window.draw(Find_Path);
            if (f == true)
            {
                hmin_text.setString(to_string(rec));
                window.draw(hmin_text);
            };
            window.draw(name4_text);
            window.draw(name_text);
            window.draw(name1_text);
            window.draw(name2_text);
            window.draw(name3_text);
            window.draw(min_path_txt);
            window.draw(textes[i]);
        }
        window.display();
    }
}
template <class T>
void Graph<T>::Put_inLbls(T& startVertex)
{
    for (int i = 0, size = List_of_vertexes.size(); i < size; ++i)
        Labels_list[i] = 99999999;
    int pos = GetVertPos(startVertex);
    Labels_list[pos] = 0;
};
template <class T>
bool Graph<T>::vse_visited(vector<bool>& visitedVerts)
{
    bool flag = true;
    for (int i = 0; i < this->List_of_vertexes.size(); i++)
        if (visitedVerts[i] != true)
            flag = false;
    return flag;
};
template <class T>
void Graph<T>::DXTRA(T& startVertex)
{
    for (int i = 0; i < List_of_vertexes.size(); i++)
        for (int j = 0; j < List_of_vertexes.size(); j++)
            if (Matrix[i][j] < 0)
                return;

    if (GetVertPos(startVertex) == -1)
        return;
    vector<bool> visitedVerts(List_of_vertexes.size());
    fill(visitedVerts.begin(), visitedVerts.end(), false);
    this->Put_inLbls(startVertex);
    T cursedsrch = startVertex;
    vector<T> Sosedi;
    while (!this->vse_visited(visitedVerts))
    {
        Sosedi = this->GetINFO(cursedsrch);
        int startLabel = Labels_list[GetVertPos(cursedsrch)];
        T* Min_Sosed = nullptr;
        int minW = 1000;

        for (int i = 0; i < Sosedi.size(); ++i)
        {
            int weight = this->GetWeight(cursedsrch, Sosedi[i]);
            int nIndex = this->GetVertPos(Sosedi[i]);
            int nextLabel = Labels_list[nIndex];
            if (startLabel + weight < nextLabel)
                Labels_list[nIndex] = startLabel + weight;
            if (!visitedVerts[nIndex] && minW > Labels_list[nIndex])
            {
                minW = Labels_list[nIndex];
                Min_Sosed = &Sosedi[i];
            };
        };
        visitedVerts[GetVertPos(cursedsrch)] = true;
        if (Min_Sosed != nullptr)
            cursedsrch = *Min_Sosed;
    };
};
template<class T>
inline Graph<T>::Graph(const int& size)
{
    this->Labels_list = vector<int>(size);
    this->maxSize = size;
    this->Matrix = vector<vector<int>>(size, vector<int>(size));
    for (int i = 0; i < this->maxSize; ++i)
    {
        for (int j = 0; j < this->maxSize; ++j)
        {
            this->Matrix[i][j] = 0;
        };
    };
};

template<class T>
inline void Graph<T>::ShowM()
{
    for (int i = 0; i < this->maxSize; ++i)
    {
        for (int j = 0; j < this->maxSize; ++j)
        {
            cout << this->Matrix[i][j] << ' ';
        };
        cout << endl;
    }
};

template<class T>
inline bool Graph<T>::Emptiness()
{
    return this->List_of_vertexes.size() == 0;
};
template<class T>
inline bool Graph<T>::FullTub()
{
    return this->List_of_vertexes.size() == this->maxSize;
};
template<class T>
inline int Graph<T>::GetVertPos(const T& v)
{
    for (int i = 0; i < this->List_of_vertexes.size(); ++i)
    {
        if (this->List_of_vertexes[i] == v)
            return i;
    }
    return -1;
};
template<class T>
inline int Graph<T>::GetCountVerts()
{
    return this->List_of_vertexes.size();
};
template<class T>
inline void Graph<T>::insertVertex(const T& vert)
{
    if (this->FullTub())
    {
        cout << "Невозможно добавить вершину !!!" << endl;
        return;
    };
    this->List_of_vertexes.push_back(vert);
};
template<class T>
int Graph<T>::GetCountLines()
{
    int count = 0;
    if (!this->IsEmpty())
    {
        for (int i = 0; i < this->List_of_vertexes.size(); ++i)
        {
            for (int j = 0; j < this->List_of_vertexes.size(); ++j)
            {
                if (this->Matrix[i][j] != 0)
                    count++;
            }
        }
    }
    return count;
};
template<class T>
inline int Graph<T>::GetWeight(const T& v1, const T& v2)
{
    if (this->Emptiness())
        return 0;
    int v1_p = this->GetVertPos(v1);
    int v2_p = this->GetVertPos(v2);
    if (v1_p == -1 || v2_p == -1)
    {
        cout << "Одного или нескольких узлов не существует !" << endl;
        return 0;
    };
    return this->Matrix[v1_p][v2_p];
};
template<class T>
vector<T> Graph<T>::GetINFO(const T& vertex) {
    vector<T> INFOlist;
    int pos = this->GetVertPos(vertex);
    if (pos != -1)
    {
        for (int i = 0; i < this->List_of_vertexes.size(); ++i)
        {
            if (this->Matrix[pos][i] != 0)
                INFOlist.push_back(this->List_of_vertexes[i]);
        }
    }
    return INFOlist;
};
template<class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight) {
    if (GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
        int vertPos1 = GetVertPos(vertex1);
        int vertPos2 = GetVertPos(vertex2);

        if (this->Matrix[vertPos1][vertPos2] != 0)
        {
            cout << "Ребро между вершинами уже есть" << endl;
            return;
        }
        else
        {
            this->Matrix[vertPos1][vertPos2] = weight;
            this->Matrix[vertPos2][vertPos1] = weight;
        }
    }
    else
    {
        cout << "Одного или нескольких узлов не существует ! " << endl;
        return;
    }
};
template<class T>
void Graph<T>::Print() {
    if (!this->Emptiness())
    {
        cout << "Ваша матрица смежности для графа :) : " << endl;
        cout << "0  ";
        for (int i = 0; i < List_of_vertexes.size(); ++i)
        {
            cout << List_of_vertexes[i] << "  ";
        }
        cout << endl;
        for (int i = 0; i < this->List_of_vertexes.size(); ++i)
        {
            cout << this->List_of_vertexes[i] << " ";
            for (int j = 0; j < this->List_of_vertexes.size(); ++j)
            {
                cout << " " << this->Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else 
        cout << "Похоже граф пуст :( " << endl;
}
int main()
{
    int F1;
    setlocale(0, "");
    locale::global(locale(""));
    cout.imbue(locale());
    int F2, TTyTb; string vertex, Start, End;
    cout << " Количество вершин -> "; cin >> F2; cout << endl;
    cout << " Количество граф -> "; cin >> F1; cout << endl;
    Graph<string> p(F2);
    Graph<string> g(20);
    p.ShowM();
    for (int i = 0; i < F2; ++i)
    {
        cout << " Вершина -> "; cin >> vertex;
        p.insertVertex(vertex);
        g.insertVertex(vertex);
        cout << endl;
    }
    for (int i = 0; i < F1; ++i)
    {
        cout << " Начальная -> "; cin >> Start; cout << endl;
        cout << " Конечная -> "; cin >> End; cout << endl;
        cout << " Номер пути -> "; cin >> TTyTb; cout << endl;
        string* end_vert = &End;
        p.InsertEdge(Start, End, TTyTb);
        g.InsertEdge(Start, End, TTyTb);
    }
    cout << endl;
    g.Print();
    g.ADD("N", (F2 + 1));
    g.InsertEdge("1", "N", 0);
    g.DRAW();
    g.Print();
    vector<bool> visitedVerts(g.maxSize, false);
}
