#include "stdafx.h"
#include "CppUnitTest.h"

#include <iostream>
#include "CrtCheckMemory.h"
#include "Graph.h"
using std::string;
using std::vector;


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	static vector<string> testVec;

	TEST_CLASS(GraphTest)
	{
	public:

		template<class V>
		static void ToVector(V data)
		{
			testVec.push_back(data);
		}

		TEST_METHOD_INITIALIZE(Init)
		{
			testVec.clear();
		}

		TEST_METHOD(GraphDefaultConstructorTest)
		{
			 
			CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				Assert::IsTrue(graph.IsEmpty());
			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphCopyTest)
		{

			try
			{
				Graph<string, string> graph;


				graph.InsertVertex("Grant's Pass");
				graph.InsertVertex("Ashland");

				Arc<string, string> arcGrantsPass(graph.GetVertex("Grant's Pass"), 60, "I-5");
				Arc<string, string> arcAshland(graph.GetVertex("Ashlass"), 70, "I-5");
				graph.InsertArc("Ashland", "Grant's Pass", arcGrantsPass);
				graph.InsertArc("Grant's Pass", "Ashland", arcAshland);


				Graph<string, string> graph2(graph);

				graph2.SetFunction(ToVector);
				graph2.BreadthFirst();

				string array1[] = { "Grant's Pass", "Ashland" };

				for (int i = 0; i < testVec.size(); i++)
				{
					Assert::AreEqual(array1[i], testVec[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphAssignmentTest)
		{

			//CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;


				graph.InsertVertex("Grant's Pass");
				graph.InsertVertex("Ashland");

				Arc<string, string> arcGrantsPass(graph.GetVertex("Grant's Pass"), 60, "I-5");
				Arc<string, string> arcAshland(graph.GetVertex("Ashlass"), 70, "I-5");
				graph.InsertArc("Ashland", "Grant's Pass", arcGrantsPass);
				graph.InsertArc("Grant's Pass", "Ashland", arcAshland);

				Graph<string, string> graph2 = graph;

				graph2.SetFunction(ToVector);
				graph2.BreadthFirst();

				string array1[] = { "Grant's Pass", "Ashland" };

				for (int i = 0; i < testVec.size(); i++)
				{
					Assert::AreEqual(array1[i], testVec[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphPurgetest)
		{

			CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;

				string temp = "Grant's Pass";

				graph.InsertVertex(temp);

				Assert::IsFalse(graph.IsEmpty());
				graph.Purge();
				Assert::IsTrue(graph.IsEmpty());
			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphInsertVertextest)
		{
			 
			CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;

				string temp = "Grant's Pass";

				graph.InsertVertex(temp);

				Assert::IsFalse(graph.IsEmpty());
			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphDeleteVertextest)
		{			 
			try
			{
				Graph<string, string> graph;

				graph.InsertVertex("Grant's Pass");
				graph.InsertVertex("Ashland");

				graph.DeleteVertex("Ashland");

				graph.SetFunction(ToVector);
				graph.BreadthFirst();

				string array1[] = { "Grant's Pass" };

				for (int i = 0; i < testVec.size(); i++)
				{
					Assert::AreEqual(array1[i], testVec[i]);
				}

				Assert::IsFalse(graph.IsEmpty());
			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphInsertArcTest)
		{
			//	CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				string port = "Grant's Pass";
				string salem = "Ashland";
				graph.InsertVertex("Grant's Pass");
				graph.InsertVertex(salem);

				Arc<string, string> arcPortland(graph.GetVertex("Grant's Pass"), 60, "I-5");
				Arc<string, string> arcSalem(graph.GetVertex("Ashland"), 70, "I-5");
				graph.InsertArc("Ashland", "Grant's Pass", arcPortland);
				graph.InsertArc("Grant's Pass", "Ashland", arcSalem);

				graph.SetFunction(ToVector);
				graph.BreadthFirst();

				string array1[] = { "Grant's Pass", "Ashland" };

				for (int i = 0; i < testVec.size(); i++)
				{
					Assert::AreEqual(array1[i], testVec[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphDeleteArcTest)
		{
			try
			{
				Graph<string, string> graph;
				Vertex<string, string> * Vertex1, *Vertex2;
				 
				 
				graph.InsertVertex("Grant's Pass");
				graph.InsertVertex("Ashland");

				Arc<string, string> arcGrantsPass(graph.GetVertex("Grant's Pass"), 60, "I-5");
				Arc<string, string> arcAshland(graph.GetVertex("Ashlass"), 70, "I-5");
				graph.InsertArc("Ashland", "Grant's Pass", arcGrantsPass);
				graph.InsertArc("Grant's Pass", "Ashland", arcAshland);

				graph.DeleteArc("Ashland", "Grant's Pass", arcGrantsPass);
				graph.DeleteArc("Grant's Pass", "Ashland", arcAshland);

				graph.SetFunction(ToVector);
				graph.BreadthFirst();

				string array1[] = { "Grant's Pass" };

				for (int i = 0; i < testVec.size(); i++)
				{
					Assert::AreEqual(array1[i], testVec[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphDepthFirstTest)
		{
			//CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				Vertex<string, string> * Vertex1, *Vertex2;
				graph.InsertVertex("Grant's Pass");
				graph.InsertVertex("Ashland");

				Arc<string, string> arcPortland(graph.GetVertex("Grant's Pass"), 60, "I-5");
				Arc<string, string> arcSalem(graph.GetVertex("Ashland"), 70, "I-5");
				graph.InsertArc("Ashland", "Grant's Pass", arcPortland);
				graph.InsertArc("Grant's Pass", "Ashland", arcSalem);

				graph.SetFunction(ToVector);
				graph.DepthFirst();

				string array1[] = { "Ashland", "Grant's Pass" };

				for (int i = 0; i < testVec.size(); i++)
				{
					Assert::AreEqual(array1[i], testVec[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}
	};
}