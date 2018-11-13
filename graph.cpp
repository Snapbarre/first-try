#include "graph.h"

using namespace std;

Graph::Graph(int i=0)
{

    char* token;
    for(i=0;i<nbVertex;i++)
    {
        Vertex* v(new Vertex(i));
        addVertex(v);
    }
    i=0;
    int pos;
    string myFile = "exampleUndirectedMatrix.txt";
    string nb,line;
    ifstream fichier(myFile.c_str(), ios::in);
    getline(fichier,line);
    getline(fichier,nb);
    getline(fichier,line);
    pos=fichier.tellg();
    while(getline(fichier,line))
    {
        string str = "string";
        char *cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
// do stuff
//delete [] cstr;
        token=strtok(cstr,",");
        while(token)
        {

        };

    };




}


void Graph::fileToGraph()
{
    string myFile = "exampleUndirectedMatrix.txt";
    string line;
    ifstream fichier(myFile.c_str(), ios::in);

    if(fichier)  // if the file succesfully opened
    {
        //The number of Vertices
        getline(fichier,line);
        nbVertex = atoi(line.c_str());  // atoi() convert a string in an int
        if (nbVertex < 0)
        {
            cerr << "Error: the number of vertex in the file is negative !" << endl;
            return ;
        }

        //If the graph is directed or not
        getline(fichier,line);
        if (line.compare("o"))
            isDirected = true;
        else if (line.compare("n"))
            isDirected = false;
        else
        {
                    cerr << "Error: the file does not correctly indicate if the graph is directed or not !" << endl;
                    return;
        }
        //If the graph is described by a adjency list or matrix
        getline(fichier,line);
        if (line.compare("m"))
            isMatrix = true;
        else if (line.compare("l"))
            isMatrix = false;
        else
            cerr << "Error: the file does not indicate correctly if it use an adjency list or matrix !" << endl;
        fichier.close();

        if (isDirected)
        {
            // Filling the adjency matrix datas
            if (isMatrix)
            {
                Graph(1);

                /*while (getline(fichier,line))
                {

                    //j'y arrive pas, meme avec strtok()
                }*/
            }

            //Filling the adjency list datas
            else
            {

            }
        }
        else
        {
            //Filling the adjency matrix datas
            if (isMatrix)
            {

            }

            //Filling the adjency list datas
            else
            {

            }
        }



        //fichier.close();  // closing of the file
    }

    else  // if the file did not opened correctly
        cerr << "Error: while opening the file, the graph is empty !" << endl;
}




ostream& operator<<(ostream& os, const Graph& g)
{
    os << "This Graph contains " << g.nbVertex << " vertex(es)." << endl;

    if (g.isDirected)
        os << "It is a directed graph ";
    else
        os << "It is a non directed graph ";

    if (g.isMatrix)
        os << "defined by an adjency matrix :" << endl;
    else
        os << "defined by an adjency list :" << endl;

    if (g.listVertex.empty())
        os << "The list of Vertexes is empty !" << endl;
    else
    {
        os << "Vertex list: ";
        for (int i = 0; i < g.listVertex.size(); i++)
        {
            os << "V" << g.listVertex[i]->getId() << ", ";
        }
        os << endl;
    }

    if (g.listEdge.empty())
        os << "The list of Edges is empty !" << endl;
    else
    {
        for (int i = 0; i < g.listEdge.size(); i++)
        {
            os << "E" << g.listEdge[i]->getId() << "(V" << g.listEdge[i]->getSrc()->getId() << ";V" << g.listEdge[i]->getDst()->getId() << "), ";
        }
        os << endl;
    }

    if (g.isMatrix)
    {

    }
    else
    {

    }


    return os;
}
