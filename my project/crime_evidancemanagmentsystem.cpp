// ============================================================
//   CRIME EVIDENCE MANAGEMENT SYSTEM
//   Language : C++
//   Loops    : for, while
//   Conditions: if, else if, else
//   Data Str : Parallel Arrays
// ============================================================

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
    // ==================== DATA ==========================

    string evidenceID[100], caseNo[100], evidenceType[100];
    string statusArr[100], dateAdded[100], description[100], officerName[100];

    string historyLog[200], historyAction[200];

    int totalRecords = 0;
    int totalHistory = 0;
    int role = 0;

    while (role != 3)
    {
        system("cls");
        cout << "\n";
        cout << "  +***********************************************+\n";
        cout << "  |     CRIME EVIDENCE MANAGEMENT SYSTEM          |\n";
        cout << "  +************************************************+\n";
        cout << "  |                                                |\n";
        cout << "  |   [1]  Admin Login                            |\n";
        cout << "  |   [2]  Viewer Login                           |\n";
        cout << "  |   [3]  Exit                                   |\n";
        cout << "  |                                                |\n";
        cout << "  +------------------------------------------------+\n";
        cout << "   Enter Choice: ";
        cin >> role;

        // ==================== ADMIN ====================
        if (role == 1)
        {
            string password;
            system("cls");
            cout << "\n";
            cout << "  *------------------------------------------------*\n";
            cout << "  |               ADMIN AUTHENTICATION             |\n";
            cout << "  *------------------------------------------------*\n";
            cout << "\n   Enter Password: ";
            cin >> password;

            if (password != "police123")
            {
                cout << "\n   [!] Access Denied! Incorrect Password.\n";
                cout << "\n   Press any key to try again...";
                getch();
                continue;
            }

            int choice = 0;

            while (choice != 10)
            {
                system("cls");
                cout << "\n";
                cout << "  +================================================+\n";
                cout << "  |              ADMIN CONTROL PANEL               |\n";
                cout << "  +================================================+\n";
                cout << "  |                                                |\n";
                cout << "  |   [1]  Add New Evidence                       |\n";
                cout << "  |   [2]  Delete Evidence                        |\n";
                cout << "  |   [3]  Update Status                          |\n";
                cout << "  |   [4]  Search by Case Number                  |\n";
                cout << "  |   [5]  View All Records                       |\n";
                cout << "  |   [6]  View History Log                       |\n";
                cout << "  |   [7]  Mark Evidence as Closed                |\n";
                cout << "  |   [8]  Search by Evidence Type                |\n";
                cout << "  |   [9]  View All Open Cases                    |\n";
                cout << "  |  [10]  Logout                                 |\n";
                cout << "  |                                                |\n";
                cout << "  +------------------------------------------------+\n";
                cout << "   Enter Choice: ";
                cin >> choice;

                // ---- Add Evidence ----
                if (choice == 1)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              ADD NEW EVIDENCE                  |\n";
                    cout << "  +================================================+\n";

                    if (totalRecords >= 100)
                    {
                        cout << "\n   [!] Storage Full! Cannot add more records.\n";
                        cout << "\n   Press any key to continue...";
                        getch();
                        continue;
                    }

                    cout << "\n   Evidence ID   : ";
                    cin >> evidenceID[totalRecords];

                    cout << "   Case Number   : ";
                    cin >> caseNo[totalRecords];

                    cout << "   Evidence Type : ";
                    cin >> evidenceType[totalRecords];

                    cout << "   Date Added    : ";
                    cin >> dateAdded[totalRecords];

                    cin.ignore();
                    cout << "   Description   : ";
                    getline(cin, description[totalRecords]);

                    cout << "   Officer Name  : ";
                    getline(cin, officerName[totalRecords]);

                    statusArr[totalRecords] = "open";

                    historyAction[totalHistory] = "ADD";
                    historyLog[totalHistory] = evidenceID[totalRecords];
                    totalHistory++;
                    totalRecords++;

                    cout << "\n   [+] Evidence Record Added Successfully!\n";
                }

                // ---- Delete Evidence ----
                else if (choice == 2)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              DELETE EVIDENCE                   |\n";
                    cout << "  +================================================+\n";

                    string id;
                    cout << "\n   Enter Evidence ID: ";
                    cin >> id;

                    int found = -1;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (evidenceID[i] == id)
                        {
                            found = i;
                            break;
                        }
                    }

                    if (found == -1)
                    {
                        cout << "\n   [!] Record Not Found!\n";
                    }
                    else
                    {
                        for (int i = found; i < totalRecords - 1; i++)
                        {
                            evidenceID[i] = evidenceID[i + 1];
                            caseNo[i] = caseNo[i + 1];
                            evidenceType[i] = evidenceType[i + 1];
                            statusArr[i] = statusArr[i + 1];
                            dateAdded[i] = dateAdded[i + 1];
                            description[i] = description[i + 1];
                            officerName[i] = officerName[i + 1];
                        }
                        totalRecords--;
                        cout << "\n   [-] Record Deleted Successfully!\n";
                    }
                }

                // ---- Update Status ----
                else if (choice == 3)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              UPDATE STATUS                     |\n";
                    cout << "  +================================================+\n";

                    string id;
                    cout << "\n   Enter Evidence ID: ";
                    cin >> id;

                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (evidenceID[i] == id)
                        {
                            cout << "   Current Status : " << statusArr[i] << "\n";
                            cout << "   New Status     : ";
                            cin >> statusArr[i];
                            cout << "\n   [*] Status Updated Successfully!\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "\n   [!] Record Not Found!\n";
                }

                // ---- Search by Case ----
                else if (choice == 4)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |           SEARCH BY CASE NUMBER                |\n";
                    cout << "  +================================================+\n";

                    string c;
                    cout << "\n   Enter Case Number: ";
                    cin >> c;

                    cout << "\n   +-----------------+---------------+-----------+\n";
                    cout << "   | Evidence ID     | Case No       | Status    |\n";
                    cout << "   +-----------------+---------------+-----------+\n";

                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (caseNo[i] == c)
                        {
                            cout << "   | " << evidenceID[i]
                                 << "\t\t  | " << caseNo[i]
                                 << "\t  | " << statusArr[i] << "\t    |\n";
                            found = true;
                        }
                    }

                    if (!found)
                        cout << "   | No records found for this case number.      |\n";

                    cout << "   +-----------------+---------------+-----------+\n";
                }

                // ---- View All Records ----
                else if (choice == 5)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              ALL EVIDENCE RECORDS              |\n";
                    cout << "  +================================================+\n";

                    if (totalRecords == 0)
                    {
                        cout << "\n   [!] No records found.\n";
                    }
                    else
                    {
                        cout << "\n";
                        for (int i = 0; i < totalRecords; i++)
                        {
                            cout << "   ------------------------------------------\n";
                            cout << "   Record #" << (i + 1) << "\n";
                            cout << "   Evidence ID   : " << evidenceID[i] << "\n";
                            cout << "   Case Number   : " << caseNo[i] << "\n";
                            cout << "   Type          : " << evidenceType[i] << "\n";
                            cout << "   Date Added    : " << dateAdded[i] << "\n";
                            cout << "   Officer       : " << officerName[i] << "\n";
                            cout << "   Description   : " << description[i] << "\n";
                            cout << "   Status        : " << statusArr[i] << "\n";
                        }
                        cout << "   ------------------------------------------\n";
                        cout << "\n   Total Records: " << totalRecords << "\n";
                    }
                }

                // ---- View History ----
                else if (choice == 6)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              HISTORY LOG                       |\n";
                    cout << "  +================================================+\n";

                    if (totalHistory == 0)
                    {
                        cout << "\n   [!] No history recorded yet.\n";
                    }
                    else
                    {
                        cout << "\n";
                        for (int i = 0; i < totalHistory; i++)
                        {
                            cout << "   [" << (i + 1) << "] "
                                 << historyAction[i] << " --> " << historyLog[i] << "\n";
                        }
                    }
                }

                // ---- Mark as Closed ----
                else if (choice == 7)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |           MARK EVIDENCE AS CLOSED              |\n";
                    cout << "  +================================================+\n";

                    string id;
                    cout << "\n   Enter Evidence ID: ";
                    cin >> id;

                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (evidenceID[i] == id)
                        {
                            statusArr[i] = "closed";
                            cout << "\n   [x] Evidence " << id << " Marked as CLOSED.\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "\n   [!] Record Not Found!\n";
                }

                // ---- Search by Type ----
                else if (choice == 8)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |           SEARCH BY EVIDENCE TYPE              |\n";
                    cout << "  +================================================+\n";

                    string t;
                    cout << "\n   Enter Evidence Type: ";
                    cin >> t;

                    cout << "\n";
                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (evidenceType[i] == t)
                        {
                            cout << "   ID: " << evidenceID[i]
                                 << "  |  Type: " << evidenceType[i]
                                 << "  |  Case: " << caseNo[i] << "\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "   [!] No records found for this type.\n";
                }

                // ---- View Open Cases ----
                else if (choice == 9)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              ALL OPEN CASES                    |\n";
                    cout << "  +================================================+\n";

                    cout << "\n";
                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (statusArr[i] == "open")
                        {
                            cout << "   ID: " << evidenceID[i]
                                 << "  |  Case: " << caseNo[i]
                                 << "  |  STATUS: OPEN\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "   [!] No open cases found.\n";
                }

                // ---- Logout ----
                else if (choice == 10)
                {
                    cout << "\n   Logging out of Admin Panel...\n";
                }

                else
                {
                    cout << "\n   [!] Invalid Choice! Please enter 1-10.\n";
                }

                cout << "\n   Press any key to continue...";
                getch();
            }
        }

        // ==================== VIEWER ====================
        else if (role == 2)
        {
            int choice = 0;

            while (choice != 10)
            {
                system("cls");
                cout << "\n";
                cout << "  +================================================+\n";
                cout << "  |             INVESTIGATOR PANEL                 |\n";
                cout << "  +================================================+\n";
                cout << "  |                                                |\n";
                cout << "  |   [1]  View All Records                       |\n";
                cout << "  |   [2]  View Open Cases                        |\n";
                cout << "  |   [3]  View Closed Cases                      |\n";
                cout << "  |   [4]  Search by Case Number                  |\n";
                cout << "  |   [5]  Search by Evidence Type                |\n";
                cout << "  |   [6]  View History Log                       |\n";
                cout << "  |   [7]  View Single Record                     |\n";
                cout << "  |   [8]  Total Records Count                    |\n";
                cout << "  |   [9]  Count Open Cases                       |\n";
                cout << "  |  [10]  Back                                   |\n";
                cout << "  |                                                |\n";
                cout << "  +------------------------------------------------+\n";
                cout << "   Enter Choice: ";
                cin >> choice;

                // ---- View All ----
                if (choice == 1)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              ALL EVIDENCE RECORDS              |\n";
                    cout << "  +================================================+\n";
                    cout << "\n";

                    if (totalRecords == 0)
                    {
                        cout << "   [!] No records found.\n";
                    }
                    else
                    {
                        for (int i = 0; i < totalRecords; i++)
                        {
                            cout << "   [" << (i + 1) << "] "
                                 << evidenceID[i] << "  |  Case: " << caseNo[i]
                                 << "  |  Status: " << statusArr[i] << "\n";
                        }
                        cout << "\n   Total: " << totalRecords << " record(s).\n";
                    }
                }

                // ---- Open Cases ----
                else if (choice == 2)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              OPEN CASES                        |\n";
                    cout << "  +================================================+\n";
                    cout << "\n";

                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (statusArr[i] == "open")
                        {
                            cout << "   ID: " << evidenceID[i] << "  |  STATUS: OPEN\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "   [!] No open cases found.\n";
                }

                // ---- Closed Cases ----
                else if (choice == 3)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              CLOSED CASES                      |\n";
                    cout << "  +================================================+\n";
                    cout << "\n";

                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (statusArr[i] == "closed")
                        {
                            cout << "   ID: " << evidenceID[i] << "  |  STATUS: CLOSED\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "   [!] No closed cases found.\n";
                }

                // ---- Search by Case ----
                else if (choice == 4)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |           SEARCH BY CASE NUMBER                |\n";
                    cout << "  +================================================+\n";

                    string c;
                    cout << "\n   Enter Case Number: ";
                    cin >> c;

                    cout << "\n";
                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (caseNo[i] == c)
                        {
                            cout << "   ID: " << evidenceID[i]
                                 << "  |  Case: " << caseNo[i] << "\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "   [!] No records found for Case: " << c << "\n";
                }

                // ---- Search by Type ----
                else if (choice == 5)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |           SEARCH BY EVIDENCE TYPE              |\n";
                    cout << "  +================================================+\n";

                    string t;
                    cout << "\n   Enter Evidence Type: ";
                    cin >> t;

                    cout << "\n";
                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (evidenceType[i] == t)
                        {
                            cout << "   ID: " << evidenceID[i]
                                 << "  |  Type: " << evidenceType[i] << "\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "   [!] No records found for Type: " << t << "\n";
                }

                // ---- View History ----
                else if (choice == 6)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              HISTORY LOG                       |\n";
                    cout << "  +================================================+\n";
                    cout << "\n";

                    if (totalHistory == 0)
                    {
                        cout << "   [!] No history recorded yet.\n";
                    }
                    else
                    {
                        for (int i = 0; i < totalHistory; i++)
                        {
                            cout << "   [" << (i + 1) << "] "
                                 << historyAction[i] << " --> " << historyLog[i] << "\n";
                        }
                    }
                }

                // ---- View Single Record ----
                else if (choice == 7)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              VIEW SINGLE RECORD                |\n";
                    cout << "  +================================================+\n";

                    string id;
                    cout << "\n   Enter Evidence ID: ";
                    cin >> id;

                    bool found = false;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (evidenceID[i] == id)
                        {
                            cout << "\n   ------------------------------------------\n";
                            cout << "   Evidence ID   : " << evidenceID[i] << "\n";
                            cout << "   Case Number   : " << caseNo[i] << "\n";
                            cout << "   Type          : " << evidenceType[i] << "\n";
                            cout << "   Date Added    : " << dateAdded[i] << "\n";
                            cout << "   Officer       : " << officerName[i] << "\n";
                            cout << "   Description   : " << description[i] << "\n";
                            cout << "   Status        : " << statusArr[i] << "\n";
                            cout << "   ------------------------------------------\n";
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "\n   [!] Record Not Found!\n";
                }

                // ---- Total Records ----
                else if (choice == 8)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              TOTAL RECORDS                     |\n";
                    cout << "  +================================================+\n";
                    cout << "\n   Total Evidence Records in System: " << totalRecords << "\n";
                }

                // ---- Count Open Cases ----
                else if (choice == 9)
                {
                    system("cls");
                    cout << "\n";
                    cout << "  +================================================+\n";
                    cout << "  |              OPEN CASES COUNT                  |\n";
                    cout << "  +================================================+\n";

                    int count = 0;
                    for (int i = 0; i < totalRecords; i++)
                    {
                        if (statusArr[i] == "open")
                            count++;
                    }
                    cout << "\n   Total Open Cases: " << count << "\n";
                }

                // ---- Back ----
                else if (choice == 10)
                {
                    cout << "\n   Returning to Main Menu...\n";
                }

                else
                {
                    cout << "\n   [!] Invalid Choice! Please enter 1-10.\n";
                }

                cout << "\n   Press any key to continue...";
                getch();
            }
        }

        // ---- Exit ----
        else if (role == 3)
        {
            system("cls");
            cout << "\n";
            cout << "  +================================================+\n";
            cout << "  |         CRIME EVIDENCE MANAGEMENT SYSTEM       |\n";
            cout << "  +================================================+\n";
            cout << "\n   System closed. Goodbye!\n\n";
        }

        else
        {
            cout << "\n   [!] Invalid Input! Please enter 1, 2, or 3.\n";
            cout << "\n   Press any key to continue...";
            getch();
        }
    }

    return 0;
}