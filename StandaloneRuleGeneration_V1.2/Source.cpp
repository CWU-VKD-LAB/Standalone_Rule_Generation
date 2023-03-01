// Standalone rule generation program
#include<stdio.h>
#include<vector>
#include<iostream>
#include<cmath>

// namespace for ease
using namespace std;

// create structure to hold rule data
struct rule {
	vector<int> ruleVals;
	int expansionDirection = 0; // -1 = less than rule, 1 = greater than rule
	int coverageCounter = 0;
	int classCovered = -1; // -1 is default value, but could potentially match a data's class.
	int expansionIndex = -1; // represents the index where the expansion/rule happens
};

void clearRule(rule& usedRule)
{
	usedRule.ruleVals.clear();
	usedRule.expansionDirection = 0;
	usedRule.coverageCounter = 0;
	usedRule.classCovered = -1;
	usedRule.expansionIndex = -1;
}

// drive function
int main()
{
	// create vectors which hold the cordinate values
	// Hard coded //
	vector<int> x1 = { 0, 1 }; //2
	vector<int> x2 = { 0, 1, 2, 3 }; // 4
	vector<int> x3 = { 0, 1, 2 }; // 3
	vector<int> x4 = { 0, 1, 2 }; // 3

	// create vectors which hold the id values. Last value is class output
	// Hard coded //
	/*vector<int> id0  =	{ 0, 0, 0, 0, 1 };
	vector<int> id1  =	{ 1, 0, 0, 0, 1 };
	vector<int> id2  =	{ 1, 1, 1, 1, 1 };
	vector<int> id3  =	{ 1, 2, 1, 1, 1 };
	vector<int> id4  =	{ 1, 3, 1, 1, 1 };
	vector<int> id5  =	{ 0, 0, 2, 2, 1 };
	vector<int> id6  =	{ 0, 0, 1, 2, 1 };
	vector<int> id7  =	{ 0, 0, 0, 2, 1 };
	vector<int> id8  =	{ 1, 2, 2, 0, 1 };
	vector<int> id9  =	{ 0, 2, 2, 0, 1 };
	vector<int> id10 =	{ 1, 2, 0, 1, 2 };
	vector<int> id11 =	{ 1, 1, 0, 1, 2 };
	vector<int> id12 =	{ 1, 0, 0, 1, 2 };
	vector<int> id13 =	{ 1, 1, 2, 2, 2 };
	vector<int> id14 =	{ 0, 1, 2, 2, 2 };
	vector<int> id15 =	{ 0, 2, 2, 0, 2 };
	vector<int> id16 =  { 0, 2, 1, 0, 2 };
	vector<int> id17 =  { 0, 2, 0, 0, 2 };
	vector<int> id18 =  { 1, 1, 2, 1, 2 };
	vector<int> id19 =  { 1, 1, 2, 2, 2 };*/


	//vector<int> id0 =  { 1, 0, 0, 0, 1 };
	//vector<int> id1 =  { 2, 0, 0, 0, 1 };
	//vector<int> id2 =  { 1, 0, 0, 0, 1 };
	//vector<int> id3 =  { 2, 0, 0, 0, 1 };
	//vector<int> id4 =  { 1, 0, 0, 0, 1 };
	//vector<int> id5 =  { 0, 0, 0, 0, 1 };
	//vector<int> id6 =  { 0, 0, 0, 0, 1 };
	//vector<int> id7 =  { 0, 0, 0, 0, 1 };
	//vector<int> id8 =  { 0, 0, 0, 0, 1 };
	//vector<int> id9 =  { 0, 0, 0, 0, 1 };
	//vector<int> id10 = { 3, 0, 0, 0, 2 };
	//vector<int> id11 = { 3, 0, 0, 0, 2 };
	//vector<int> id12 = { 3, 0, 0, 0, 2 };
	//vector<int> id13 = { 3, 0, 0, 0, 2 };
	//vector<int> id14 = { 3, 0, 0, 0, 2 };
	//vector<int> id15 = { 3, 0, 0, 0, 2 };
	//vector<int> id16 = { 3, 0, 0, 0, 2 };
	//vector<int> id17 = { 3, 0, 0, 0, 2 };
	//vector<int> id18 = { 3, 0, 0, 0, 2 };
	//vector<int> id19 = { 3, 0, 0, 0, 2 };


	vector<int> id0  =	{ 0, 0, 0, 0, 1 };
	vector<int> id1  =	{ 1, 0, 0, 0, 1 };
	vector<int> id2  =	{ 2, 0, 0, 0, 1 };
	vector<int> id3  =	{ 3, 0, 0, 0, 1 };
	vector<int> id4  =	{ 4, 0, 0, 0, 1 };
	vector<int> id5  =	{ 5, 0, 0, 0, 1 };
	vector<int> id6  =	{ 6, 0, 0, 0, 1 };
	vector<int> id7  =	{ 7, 0, 0, 0, 1 };
	vector<int> id8  =	{ 8, 0, 0, 0, 1 };
	vector<int> id9  =	{ 9, 0, 0, 0, 1 };
	vector<int> id10 =	{ 10, 0, 0, 1, 2 };
	vector<int> id11 =	{ 11, 1, 0, 1, 2 };
	vector<int> id12 =	{ 12, 0, 0, 1, 2 };
	vector<int> id13 =	{ 13, 1, 2, 2, 2 };
	vector<int> id14 =	{ 14, 1, 2, 2, 2 };
	vector<int> id15 =	{ 13, 2, 2, 0, 2 };
	vector<int> id16 =  { 14, 2, 1, 0, 2 };
	vector<int> id17 =  { 14, 2, 0, 0, 2 };
	vector<int> id18 =  { 13, 1, 2, 1, 2 };
	vector<int> id19 =  { 13, 1, 2, 2, 2 };


	// create vector to hold all data
	vector<vector<int>> data;

	// put data into data vector
	data.push_back(id0 );
	data.push_back(id1 );
	data.push_back(id2 );
	data.push_back(id3 );
	data.push_back(id4 );
	data.push_back(id5 );
	data.push_back(id6 );
	data.push_back(id7 );
	data.push_back(id8 );
	data.push_back(id9 );
	data.push_back(id10);
	data.push_back(id11);
	data.push_back(id12);
	data.push_back(id13);
	data.push_back(id14);
	data.push_back(id15);
	data.push_back(id16);
	data.push_back(id17);
	data.push_back(id18);
	data.push_back(id19);

	// find the minimum and maximum for each coordinate/attribute
	vector<int> coordinateMax;
	vector<int> coordinateMin;

	//for (int dataXIndex = 0; dataXIndex < data.size(); dataXIndex++)
	//{
	//	for (int dataYIndex = 0; dataYIndex < (data.at(dataXIndex).size() - 1); dataYIndex++)
	//	{
	//		if (dataYIndex == 0)
	//		{
	//			// push the first data segment into the max and min vectors
	//			for (int firstData = 0; firstData < (data.at(dataXIndex).size() - 1); firstData++)
	//			{
	//				coordinateMax.push_back(data.at(dataXIndex).at(firstData));
	//				coordinateMin.push_back(data.at(dataXIndex).at(firstData));
	//			}
	//		}
	//		else
	//		{
	//			// if the current data is greater than the current max data
	//			if (data.at(dataXIndex).at(dataYIndex) > coordinateMax.at(dataYIndex))
	//			{
	//				coordinateMax.at(dataYIndex) = data.at(dataXIndex).at(dataYIndex);
	//			}

	//			// if the current data is less than the curren min data
	//			if (data.at(dataXIndex).at(dataYIndex) < coordinateMin.at(dataYIndex))
	//			{
	//				coordinateMin.at(dataYIndex) = data.at(dataXIndex).at(dataYIndex);
	//			}
	//		}
	//	}
	//}

	for (int dataYIndex = 0; dataYIndex < (data.at(0).size() - 1); dataYIndex++)
	{
		coordinateMax.push_back(data.at(0).at(dataYIndex));
		coordinateMin.push_back(data.at(0).at(dataYIndex));

		for (int dataXIndex = 0; dataXIndex < data.size(); dataXIndex++)
		{
			if (data.at(dataXIndex).at(dataYIndex) > coordinateMax.at(dataYIndex))
			{
				coordinateMax.at(dataYIndex) = data.at(dataXIndex).at(dataYIndex);
			}
			else if(data.at(dataXIndex).at(dataYIndex) < coordinateMin.at(dataYIndex))
			{
				coordinateMin.at(dataYIndex) = data.at(dataXIndex).at(dataYIndex);
			}
		}
	}


	// create vector of rules generated
	vector<rule> rules;

	// create temporary rule structure for information tracking
	rule* tempRule;	

	// 2d vector to hold all of the valid expandable data ids 
	vector<vector<int>> expandable;

	// 2d vector to hold all of the expansion flags
	// 1 will represent an upward expansion
	// -1 will represent a downward expansion
	vector<vector<int>> expansionFlags;

	// 2d vector to hold all of the expansion indexes
	// the value will represent the index at which the expansion was found
	vector<vector<int>> columnExpansionIndexes;

	// compare the first case against all cases to find where the absolute value of all points subtracted is 1
	// Ex: c1 = {0, 0, 1, 2} and c2 = {1, 0, 1, 2}
	// c1 - c2 = {-1, 0, 0, 0}
	// sum the result = -1
	// take the absolute value = 1
	for (int compXIndex = 0; compXIndex < data.size(); compXIndex++)
	{
		// int vector to store the index of cases which have an absolute value of 1 when compared to the comparison case
		vector<int> matches;

		// vector to hold the difference between the two cases (see example below)
		vector<int> difference;

		// clear matches
		matches.clear();

		// push the current data being compared into the first index of the matches vector
		matches.push_back(compXIndex);

		// comparison case to keep track of current case to be compared
		vector<int> comparisonCase = data.at(compXIndex);

		for (int dataXIndex = 0; dataXIndex < data.size(); dataXIndex++)
		{
			for (int dataYIndex = 0; dataYIndex < (data.at(dataXIndex).size() - 1); dataYIndex++)
			{
				// check that the comparisonX and the dataX are not the same
				if (compXIndex != dataXIndex)
				{
					// subtract the comparison data from the data being compared
					difference.push_back(((comparisonCase.at(dataYIndex)) - (data.at(dataXIndex).at(dataYIndex))));
				}

			}// close dataY

			// add together the difference and check if the absolute value of the difference is 1
			// integer to hold the sum
			int sum = 0;
			for (int diff = 0; diff < difference.size(); diff++)
			{
				// cout << "Difference Value: " << difference.at(diff) << endl;
				sum += difference.at(diff);
			}

			// cout << "Difference Sum ABS: " << abs(sum) << endl;

			// clear difference vector
			difference.clear();

			// check if the absolute value of sum is 1
			if (abs(sum) == 1)
			{
				cout << "Match " << dataXIndex << " pushed to vector" << endl;
				matches.push_back(dataXIndex);
			}

		}// close dataX

		/*
		// print matches to ensure it is working
		for (int i = 0; i < matches.size(); i++)
		{
			if (i == 0)
			{
				cout << "ID" << matches.at(i) << " has the matches of: " << endl;
			}
			else
			{
				cout << "\tMatch " << i << ":" << " ID" << matches.at(i) << endl;
			}
		}
		*/

		// check if the matches can be expanded
		//=====NOTE: THIS DOES NOT CURRENTLY WORK=====//
		for (int match = 0; match < matches.size(); match++)
		{
			// boolean variable to check if an expandable attribute has already been found
			// this needs to be checked since there can only be one expansion
			bool expansionFound = false;

			// temporary vector to hold this comparisons expandable flags
			vector<int> tempExpansionFlags;

			// temporary vector to hold this comparisons expandable IDs
			vector<int> tempId;

			// temporary vector to hold the index of the expansion
			vector<int> tempColumnInd;

			// the first value in the match vector is the id of the original compared data
			if (match > 0)
			{
				// iterate over the matched dataID to determine if it can be expanded
				//changed dataIndex -> columnIndex
				for (int columnIndex = 0; columnIndex < (data.at(matches.at(match)).size() - 1); columnIndex++)
				{

					// check if the match can be expanded upwards
					if (expansionFound == false && comparisonCase.at(columnIndex) == (data.at(matches.at(match)).at(columnIndex) + 1) )
					{
						// set the expansion found flag to true
						expansionFound = true;

						// set the expand flag to show it is an downward expansion
						//changed tempFlags -> tempExpansionFlags
						tempExpansionFlags.push_back(-1);

						// record the expansion index
						//change tempInd -> tempColumnInd
						tempColumnInd.push_back(columnIndex);

						/*
						cout << "Downward Expansion Found in match #" << match << endl;
						cout << "\tData at: " << dataIndex << " is: " << comparisonCase.at(dataIndex) << endl;
						cout << "\tExpansion: " << matches.at(match) << " at: " << match << " is: " << (data.at(matches.at(match)).at(dataIndex) + 1) << endl;
						*/
					}
					// check if the match can be expanded downwards
					else if (expansionFound == false && comparisonCase.at(columnIndex) == (data.at(matches.at(match)).at(columnIndex) - 1) )
					{
						// set the expansion found flag to true
						expansionFound = true;

						// set the expand flag to show it is an upward expansion
						tempExpansionFlags.push_back(1);

						// record the expansion index
						tempColumnInd.push_back(columnIndex);

						/*
						cout << "Upward Expansion Found in match #" << match << endl;
						cout << "\tData at: " << dataIndex << " is: " << comparisonCase.at(dataIndex) << endl;
						cout << "\tExpansion: " << matches.at(match) << " at: " << match << " is: " << (data.at(matches.at(match)).at(dataIndex) + 1) << endl;
						*/
					}
					// this means that there are more than one expansions in the match
					// Ex: comparison Case = {0, 1, 0 ,0}
					// 	   match case = {1, 0, 0, 1}
					// In the above example, the difference in the sums is an absolute value of 1, but there is more than one possible expansion
					else if (expansionFound == true && comparisonCase.at(columnIndex) != (data.at(matches.at(match)).at(columnIndex)))
					{
						// remove the last flag pushed into the expansion flag vector
						if (tempExpansionFlags.size() > 0)
						{
							tempExpansionFlags.pop_back();
						}

						if (tempColumnInd.size() > 0)
						{
							tempColumnInd.pop_back();
						}

						break;
					}
					// check if there is an expansion that is too large or too small
					// Ex: ID1 (0, 0, 0, 1), ID2 (0, 0, 0, 3)
					// Ex: ID1 (0, 0, 0, 3), ID2 (0, 0, 0, 1)
					else if ((comparisonCase.at(columnIndex) > (data.at(matches.at(match)).at(columnIndex) + 1)) || (comparisonCase.at(columnIndex) < (data.at(matches.at(match)).at(columnIndex) - 1)))
					{
						// clear the last flag pushed if there are any
						if (tempExpansionFlags.size() > 0)
						{
							tempExpansionFlags.pop_back();
						}

						break;
					}
					// else the comparison case and the data are the same value
					else
					{
						continue;
					}
				} 
				// end dataIndex

				if (expansionFound == true && tempExpansionFlags.size() > 0)
				{
					// add the comparison ID to the expandable vector
					tempId.push_back(matches.at(0));

					// add the match which can be expanded to to the expandable vector
					tempId.push_back(matches.at(match));

					// push the entire temporary vector into the expandable vector
					expandable.push_back(tempId);

					// add the expansion flags from the temporary flag
					expansionFlags.push_back(tempExpansionFlags);

					// add the expansion indexes from the temporary indexes
					columnExpansionIndexes.push_back(tempColumnInd);
				}
			}
		} // end matches

		// clear the expandable and expansion flags
		// expandable.clear();
		// expansionFlags.clear();

	}// close compXIndex

	cout << "\n";

	// print the expansions to ensure it is working
	for (int i = 0; i < expandable.size(); i++)
	{
		for (int j = 0; j < expandable.at(i).size(); j++)
		{
			if (j == 0)
			{
				cout << "ID" << expandable.at(i).at(j) << " can expand to: " << endl;
			}
			else
			{
				cout << "\tExpand " << i << ":" << " ID" << expandable.at(i).at(j) << endl;
				cout << "\tExpand " << i << " Direction " << ": " << expansionFlags.at(i).at(j - 1) << " at index: " << columnExpansionIndexes.at(i).at(j - 1) << endl;
			}
		}
	}

	cout << "\n";


	// check for less than rules
	// Condition: index is the same
	//			  Ex: expansion index = 0
	//			  Data 1 = {0, 1, 1, 1}
	//			  Data 2 = {1, 1, 1, 1}
	//			  Data 3 = {2, 1, 1, 1}
	//			  Max for X1 = 2, min = 0
	//			  Rule: x1 <= 2, x2 = 1, x3 = 1, x4 = 1
	for (int curExpansionIndex = 0; curExpansionIndex < expandable.size(); curExpansionIndex++)//picks up index of the expandable vector
	{
		// get the first index of the expandable vector which is the data index that is being expanded upon
		// data index = the row of what is being expanded upon from the expansion of dataX. 
		int curRowExpansionDataIndex = expandable.at(curExpansionIndex).at(0);

		//will always only loop 1 time?
		//going to look at the expansions for the vector
		for (int expand = 1; expand < expandable.at(curExpansionIndex).size(); expand++)
		{
			// create a boolean value to end the while loop if the expansion cannot be made into a rule
			bool endExpansionRuleCheck = false;

			// create a new rule
			tempRule = new rule;

			tempRule->expansionDirection = 1;

			// pushback the dataIndex to follow the chain of expansion
			vector<int> expansionChain;


			expansionChain.push_back(curRowExpansionDataIndex);

			// record the expansion index to determine which position should be checked in the chain
			//changed curExpansionIndex -> columnExpansionIndexTemp; might need to be changed back
			int curColumnExpansionDataIndex = columnExpansionIndexes.at(curExpansionIndex).at(0);

			// add the expansionIndex to the rule
			tempRule->expansionIndex = curColumnExpansionDataIndex;

			//the ongoingExpansionIndex is what will be used inside of the for loop
			//this way the curExpansionIndex can be properly used in further iterations of the for loop we are inside of
			int ongoingExpansionIndex = curExpansionIndex;
			//going to loop through all of the expansions that can be expanded from the intitial expanded-from var
			while (endExpansionRuleCheck == false)
			{
				// if the data on the expansion coordinate is not the minimum value, break out of the loop
				//if (data.at(curRowExpansionDataIndex).at(curColumnExpansionDataIndex) != coordinateMin.at(curColumnExpansionDataIndex) )
				//{
				//	endExpansionRuleCheck = true;
				//	//break;
				//}
				/*else
				{*/
					// if the program makes it here, then the data is the minimum value of that coordinate
					// this means that the expansion from this point can be a less than rule

					// add the expansion to the chain
					expansionChain.push_back(expandable.at(ongoingExpansionIndex).at(1));

					bool ruleExpansionFound = false;


					// search if the expandable coordinate can be expanded itself
					for (int i = 0; i < expandable.size(); i++)
					{
						// check if the expansion from the original coordinate has any expansions of its own
						if (expandable.at(i).at(0) == expandable.at(ongoingExpansionIndex).at(1) //if the row matches
							&& columnExpansionIndexes.at(i).at(0) == curColumnExpansionDataIndex //and if the column matches
							&& expansionFlags.at(i).at(0) == 1 //and if the flag matches
							&& data.at(expandable.at(i).at(1)).at(data.at(0).size() - 1) == data.at(expandable.at(ongoingExpansionIndex).at(1)).at(data.at(0).size() - 1))//and if the class matches
						{
							//// check if the next expansion can expand along the same index as the previous expansion
							////will only ever loop once?
							//for (int j = 0; j < columnExpansionIndexes.at(i).size(); j++)
							//{
							//	// cout << "I am making it here " << j << endl;
							//	// if the expansion can expand on the same index, is an upward expansion, and shares the same class, then it can be used 
							//	if (columnExpansionIndexes.at(i).at(j) == curColumnExpansionDataIndex && expansionFlags.at(i).at(j) == -1) // && data.at(expandable.at(i).at(j + 1)).at(data.at(i).size() - 1) == data.at(dataIndex).at(data.at(i).size() - 1))
							//	{
									cout << "im getting here\n";
									curRowExpansionDataIndex = expansionChain.at(expansionChain.size() - 1);
									ruleExpansionFound = true;
									ongoingExpansionIndex = i;
									break;
							/*	}
							}*/
						}
						else
						{
							ruleExpansionFound = false;
						}
					}

					//makes loop not infinite
					//check if the rule expanded in testing
					if (ruleExpansionFound == false)
					{
						endExpansionRuleCheck = true;
					}
				//}
				cout << "I am looping" << endl;
			} // end while loop

			// determine if a rule has been generated
			if (expansionChain.size() > 1)
			{
				// add the data to the temporary rule so that it can be added to the rule vector
				// copy the coordinates into the ruleVals vector
				for (int coords = 0; coords < expansionChain.size(); coords++)
				{
					tempRule->ruleVals.push_back(expansionChain.at(coords));
				}

				// fill the rule expansion direction
				tempRule->expansionDirection = -1;

				// calculate coverage of the rule
				tempRule->coverageCounter = tempRule->ruleVals.size();

				// put the class in the rule
				tempRule->classCovered = data.at(tempRule->ruleVals.at(0)).at(data.at(tempRule->ruleVals.at(0)).size() - 1);

				// put the tempRule into the rule vector
				rules.push_back(*tempRule);

				// clear the tempRule so it can be used again
				clearRule(*tempRule);

				// clear the expansionChain so it can be used again
				expansionChain.clear();
			}
			else
			{
				// if the expansion chain vector is smaller 2, there is no possible less than rule
				// clear the expansion Chain vector
				expansionChain.clear();
			}
		} // end expansion innner for loop
	} // end expansion outer for loop


	//counting number of cases per class. Currently only recognizes two classes
	int class1Num = 0;
	int class2Num = 0;
	//determine the column index in the data which holds the class number (the last column in the data)
	int columnCount = data.at(0).size() - 1;
	//checks the last class column for every set (row of data) and increases either class1Num or class2Num depending on if the set is in class 1 or 2
	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i).at(columnCount) == 1)
		{
			class1Num++;
		}
		else
		{
			class2Num++;
		}
	}

	cout << "Total rules: " << rules.size() << endl;

	// print results
	for(int i = 0; i < rules.size(); i++)
	{
		cout << "Rule " << i + 1 << " : " << endl;

		for (int dataPrint = 0; dataPrint < data.at(rules.at(i).ruleVals.at(rules.at(i).ruleVals.size() - 1)).size() - 1; dataPrint++)
		{
			if (dataPrint == rules.at(i).expansionIndex)
			{
				cout << "X" << (dataPrint + 1) << " <= " << data.at(rules.at(i).ruleVals.at(rules.at(i).ruleVals.size() - 1)).at(dataPrint) << endl;
			}
			else
			{
				cout << "X" << (dataPrint + 1) << " = " << data.at(rules.at(i).ruleVals.at(rules.at(i).ruleVals.size() - 1)).at(dataPrint) << endl;
			}
		}

		// print the class the rule covers
		cout << "Rule " << (i+1) << " covers class " << rules.at(i).classCovered << endl;

		cout << "Number of cases covered: " << rules.at(i).coverageCounter << endl;

		int curClass = rules.at(i).classCovered == 1 ? class1Num : class2Num;
		double classCoveragePercent = ((double)rules.at(i).coverageCounter / curClass * 100);
		cout << "Coverage of class: " << classCoveragePercent << "%" << endl;

		// num cases covered divided by the number of cases in the data
		double allCaseCoveragePercent = ((double)rules.at(i).coverageCounter / data.size() * 100);
		cout << "Coverage of all cases: " << (allCaseCoveragePercent) << "%" << endl;

		// cout << "Number of class 1 cases covered: " << rules.at(i).classCovered << endl;
		
		cout << endl << endl;
	}

	cout << "You have reached the end" << endl;

} // end of main method

