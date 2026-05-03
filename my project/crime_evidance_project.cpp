// ################################################################
// #                                                              #
// #        CRIME EVIDENCE MANAGEMENT SYSTEM  v2.0               #
// #        ----------------------------------------             #
// #        Language   : C++                                      #
// #        Loops      : for, while                               #
// #        Conditions : if, else if, else                        #
// #        Data Str   : Parallel Arrays                          #
// #                                                              #
// ################################################################

#include <iostream>
#include <string>
using namespace std;

// ================================================================
//   SECTION 1 : GLOBAL PARALLEL ARRAYS
//   ---------------------------------------------------------------
//   All evidence data is stored in parallel arrays — each index
//   represents one complete evidence record across all arrays.
//   Max capacity: 100 evidence records, 200 history events.
// ================================================================

// --- Evidence record fields (index i = one full record) ---
string evidenceID[100];   // Unique ID for each piece of evidence
string caseNo[100];       // Case number this evidence belongs to
string evidenceType[100]; // Category: weapon / document / digital / other
string statusArr[100];    // Current status: open / closed / under-review
string dateAdded[100];    // Date evidence was logged (DD/MM/YYYY)
string description[100];  // Free-text description of the evidence
string officerName[100];  // Name of officer who logged the evidence
int totalRecords = 0;     // Counter — tracks how many records exist

// --- Audit history fields (index i = one logged event) ---
string historyLog[200];    // Details / description of what happened
string historyDate[200];   // Date the event occurred (placeholder)
string historyAction[200]; // Type of action: ADD / DELETE / UPDATE / SORT
int totalHistory = 0;      // Counter — tracks how many history events exist

// ================================================================
//   SECTION 2 : UTILITY / HELPER FUNCTIONS
//   ---------------------------------------------------------------
//   Small reusable functions called throughout the program to
//   avoid code repetition and keep other functions clean.
// ================================================================

// ----------------------------------------------------------------
//   clrscr()
//   Clears the terminal screen using the Windows CLS command.
//   Called at the start of every menu and every function screen
//   so old output does not pile up and confuse the user.
// ----------------------------------------------------------------
void clrscr()
{
    system("cls");
}

// ----------------------------------------------------------------
//   pause()
//   Waits for the user to press ENTER before continuing.
//   Used at the end of every function so the user can read the
//   output before the screen gets cleared again.
// ----------------------------------------------------------------
void pause()
{
    cout << endl;
    cout << "  +----------------------------------------------------------+" << endl;
    cout << "  |   Press ENTER to go back to menu...                      |" << endl;
    cout << "  +----------------------------------------------------------+" << endl;
    cin.ignore(); // Discard leftover newline from previous cin >>
    cin.get();    // Wait for user to press ENTER
}

// ----------------------------------------------------------------
//   addHistory()
//   Logs an action into the history arrays for audit purposes.
//   Parameters:
//     action — short label like "ADD", "DELETE", "UPDATE"
//     detail — longer description of what changed
//   Stops logging silently if the history buffer is full (200).
// ----------------------------------------------------------------
void addHistory(string action, string detail)
{
    if (totalHistory < 200)
    {
        historyAction[totalHistory] = action;
        historyLog[totalHistory] = detail;
        historyDate[totalHistory] = "2025-01-01"; // Placeholder date
        totalHistory++;
    }
    // If buffer is full (totalHistory >= 200), skip silently — no crash
}

// ----------------------------------------------------------------
//   printBanner()
//   Prints the main ASCII system banner shown at the top of
//   every screen to give the program a consistent look.
// ----------------------------------------------------------------
void printBanner()
{
    cout << "  +============================================================+" << endl;
    cout << "  |       C R I M E   E V I D E N C E   S Y S T E M          |" << endl;
    cout << "  |              Secure Database  |  Auth. Access Only         |" << endl;
    cout << "  +============================================================+" << endl;
}

// ----------------------------------------------------------------
//   printLine() / printThickLine()
//   Two styles of divider to separate sections visually.
//     printLine()      — thin --- border for inner separators
//     printThickLine() — thick === border for menu footers
// ----------------------------------------------------------------
void printLine()
{
    cout << "  +------------------------------------------------------------+" << endl;
}
void printThickLine()
{
    cout << "  +============================================================+" << endl;
}

// ----------------------------------------------------------------
//   findEvidence()
//   Searches the evidenceID array for a matching ID string.
//   Uses a while loop to walk through all active records.
//   Returns:
//     The array index (0-based) if the ID is found.
//     -1 if the ID is NOT found in any record.
// ----------------------------------------------------------------
int findEvidence(string id)
{
    int i = 0;
    while (i < totalRecords)
    {
        if (evidenceID[i] == id)
        {
            return i; // Match found — return position immediately
        }
        i++;
    }
    return -1; // Walked all records without a match
}

// ----------------------------------------------------------------
//   printRecord()
//   Prints a single evidence record in a neatly boxed format.
//   Parameter: i — the array index of the record to display.
//   Called by any function that needs to display record details.
// ----------------------------------------------------------------
void printRecord(int i)
{
    cout << "  +------------------------------------------------------------+" << endl;
    cout << "  |  # Record       : " << i + 1 << endl;
    cout << "  |  Evidence ID    : " << evidenceID[i] << endl;
    cout << "  |  Case No.       : " << caseNo[i] << endl;
    cout << "  |  Type           : " << evidenceType[i] << endl;
    cout << "  |  Status         : [ " << statusArr[i] << " ]" << endl;
    cout << "  |  Date Added     : " << dateAdded[i] << endl;
    cout << "  |  Description    : " << description[i] << endl;
    cout << "  |  Logged By      : " << officerName[i] << endl;
    cout << "  +------------------------------------------------------------+" << endl;
}

// ================================================================
//   SECTION 3 : ADMIN FUNCTIONS  (Police Officer)
//   ---------------------------------------------------------------
//   Full read + write access. Protected by password at login.
//   Each function handles one menu option completely.
// ================================================================

// ----------------------------------------------------------------
//   addEvidence()   [ Admin Option 1 ]
//   Collects all fields from the user and stores them into the
//   next available slot in the parallel arrays.
//   Validates:
//     - Array capacity (max 100 records)
//     - Duplicate Evidence ID (must be unique)
//   Auto-sets status to "open" for every new record.
//   Logs the action to history when done.
// ----------------------------------------------------------------
void addEvidence()
{
    clrscr();
    printBanner();
    cout << "  |  [+]  ADD NEW EVIDENCE RECORD                              |" << endl;
    printLine();

    // Guard — stop if the array is already at max capacity
    if (totalRecords >= 100)
    {
        cout << "  [!!] System is full (100 records). Cannot add more." << endl;
        pause();
        return;
    }

    // --- Get and validate Evidence ID ---
    string newID;
    cout << "  Enter Evidence ID   : ";
    cin >> newID;

    // Reject duplicate IDs — each piece of evidence must be unique
    if (findEvidence(newID) != -1)
    {
        cout << "  [!!] That Evidence ID already exists. Returning to menu." << endl;
        pause();
        return;
    }

    // --- Store the ID at the next free slot ---
    evidenceID[totalRecords] = newID;

    // --- Collect remaining fields one by one ---
    cout << "  Enter Case Number   : ";
    cin >> caseNo[totalRecords];

    cout << "  Enter Type (weapon / document / digital / other) : ";
    cin >> evidenceType[totalRecords];

    cout << "  Enter Date Added (DD/MM/YYYY) : ";
    cin >> dateAdded[totalRecords];

    // cin.ignore() clears leftover newline so getline() works correctly
    cin.ignore();
    cout << "  Enter Description   : ";
    getline(cin, description[totalRecords]);

    cout << "  Enter Officer Name  : ";
    getline(cin, officerName[totalRecords]);

    // Auto-assign "open" as the default starting status
    statusArr[totalRecords] = "open";

    // Increment the counter AFTER all fields are safely stored
    totalRecords++;

    // --- Confirmation output ---
    printLine();
    cout << "  [OK] Evidence record added successfully!" << endl;
    cout << "       ID: " << newID << "  |  Total Records Now: " << totalRecords << endl;

    // Log this action to the audit trail
    addHistory("ADD", "Added evidence ID: " + newID);
    pause();
}

// ----------------------------------------------------------------
//   deleteEvidence()   [ Admin Option 2 ]
//   Finds a record by ID, shows it, then asks for confirmation.
//   If confirmed, removes it by shifting all arrays left by one
//   position from the deleted index — this fills the gap cleanly.
//   Logs the deleted ID and case number to audit history.
// ----------------------------------------------------------------
void deleteEvidence()
{
    clrscr();
    printBanner();
    cout << "  |  [-]  DELETE EVIDENCE RECORD                               |" << endl;
    printLine();

    // Get the ID the admin wants to delete
    string id;
    cout << "  Enter Evidence ID to delete : ";
    cin >> id;

    // Search for it — bail if not found
    int idx = findEvidence(id);
    if (idx == -1)
    {
        cout << "  [!!] Evidence ID not found. No changes made." << endl;
        pause();
        return;
    }

    // Show the record so admin can confirm it is the right one
    cout << endl;
    cout << "  Record found:" << endl;
    printRecord(idx);

    // Safety confirmation before permanent deletion
    char confirm;
    cout << "  Confirm delete? (Y / N) : ";
    cin >> confirm;

    if (confirm == 'Y' || confirm == 'y')
    {
        // Save info before wiping the slot (needed for history log)
        string deletedID = evidenceID[idx];
        string deletedCase = caseNo[idx];

        // Shift every parallel array left by one from the deleted index
        // This fills the gap without leaving empty holes in the middle
        for (int i = idx; i < totalRecords - 1; i++)
        {
            evidenceID[i] = evidenceID[i + 1];
            caseNo[i] = caseNo[i + 1];
            evidenceType[i] = evidenceType[i + 1];
            statusArr[i] = statusArr[i + 1];
            dateAdded[i] = dateAdded[i + 1];
            description[i] = description[i + 1];
            officerName[i] = officerName[i + 1];
        }
        totalRecords--; // One fewer record now

        printLine();
        cout << "  [OK] Evidence ID: " << deletedID << " deleted successfully." << endl;
        cout << "       Records remaining: " << totalRecords << endl;
        addHistory("DELETE", "Deleted evidence ID: " + deletedID + "  Case: " + deletedCase);
    }
    else
    {
        // Admin chose not to confirm — nothing changes
        cout << "  [--] Delete cancelled. No records were changed." << endl;
    }
    pause();
}

// ----------------------------------------------------------------
//   updateStatus()   [ Admin Option 3 ]
//   Looks up a record by ID and changes its status field.
//   Valid status values: open / closed / under-review
//   Saves old status before overwriting and logs the change.
// ----------------------------------------------------------------
void updateStatus()
{
    clrscr();
    printBanner();
    cout << "  |  [~]  UPDATE EVIDENCE STATUS                               |" << endl;
    printLine();

    string id;
    cout << "  Enter Evidence ID : ";
    cin >> id;

    // Find the record — if not found, stop here
    int idx = findEvidence(id);
    if (idx == -1)
    {
        cout << "  [!!] Evidence ID not found." << endl;
        pause();
        return;
    }

    // Show current status before asking for new one
    cout << "  Current Status  : [ " << statusArr[idx] << " ]" << endl;
    cout << "  New Status (open / closed / under-review) : ";
    string newStatus;
    cin >> newStatus;

    // Save old status for the history log, then overwrite
    string oldStatus = statusArr[idx];
    statusArr[idx] = newStatus;

    printLine();
    cout << "  [OK] Status updated: " << oldStatus << "  -->  " << newStatus << endl;
    addHistory("UPDATE", "Evidence " + id + " status: " + oldStatus + " -> " + newStatus);
    pause();
}

// ----------------------------------------------------------------
//   searchByCaseNo()   [ Admin Option 4 / Viewer Option 1 ]
//   Loops through all records and prints every one whose
//   caseNo field exactly matches the user's search string.
//   Shared by both admin and viewer menus (read-only operation).
// ----------------------------------------------------------------
void searchByCaseNo()
{
    clrscr();
    printBanner();
    cout << "  |  [?]  SEARCH BY CASE NUMBER                                |" << endl;
    printLine();

    string searchCase;
    cout << "  Enter Case Number : ";
    cin >> searchCase;

    // Linear scan of all active records — print every match
    int found = 0;
    for (int i = 0; i < totalRecords; i++)
    {
        if (caseNo[i] == searchCase)
        {
            found++;
            printRecord(i);
        }
    }

    // Summary line after the scan
    printLine();
    if (found == 0)
    {
        cout << "  [!] No records found for case: " << searchCase << endl;
    }
    else
    {
        cout << "  [OK] Total matching records: " << found << endl;
    }
    pause();
}

// ----------------------------------------------------------------
//   viewAllEvidence()   [ Admin Option 5 ]
//   Displays every active record in the system, numbered.
//   Prints a total count at the bottom.
//   Also called internally by sort functions to show results.
// ----------------------------------------------------------------
void viewAllEvidence()
{
    clrscr();
    printBanner();
    cout << "  |  [=]  ALL EVIDENCE RECORDS                                 |" << endl;
    printLine();

    // Edge case — nothing to show yet
    if (totalRecords == 0)
    {
        cout << "  [!] No records in the system yet." << endl;
        pause();
        return;
    }

    // Print every record using the shared printRecord() helper
    for (int i = 0; i < totalRecords; i++)
    {
        printRecord(i);
    }

    printLine();
    cout << "  [=] Total records in system: " << totalRecords << endl;
    pause();
}

// ----------------------------------------------------------------
//   sortByDate()   [ Admin Option 6 ]
//   Sorts ALL 7 parallel arrays together using bubble sort,
//   keyed on the dateAdded field.
//   User picks ascending (1) or descending (2) order.
//   PERMANENT — reorders the main arrays, not a display copy.
//   After sort, calls viewAllEvidence() to show the results.
// ----------------------------------------------------------------
void sortByDate()
{
    clrscr();
    printBanner();
    cout << "  |  [^]  SORT RECORDS BY DATE  (permanent)                    |" << endl;
    printLine();
    cout << "  1.  Ascending  (oldest first)" << endl;
    cout << "  2.  Descending (newest first)" << endl;
    cout << "  Choice : ";
    int order;
    cin >> order;

    // Bubble sort — outer pass controls how many total passes are needed
    for (int i = 0; i < totalRecords - 1; i++)
    {
        // Inner pass — compare adjacent pairs and swap if out of order
        for (int j = 0; j < totalRecords - i - 1; j++)
        {
            bool doSwap = false;

            // Ascending: swap if left date is GREATER than right
            if (order == 1 && dateAdded[j] > dateAdded[j + 1])
                doSwap = true;
            // Descending: swap if left date is LESS than right
            if (order == 2 && dateAdded[j] < dateAdded[j + 1])
                doSwap = true;

            if (doSwap)
            {
                // Must swap ALL 7 arrays together to keep records aligned
                string tmp;
                tmp = evidenceID[j];
                evidenceID[j] = evidenceID[j + 1];
                evidenceID[j + 1] = tmp;
                tmp = caseNo[j];
                caseNo[j] = caseNo[j + 1];
                caseNo[j + 1] = tmp;
                tmp = evidenceType[j];
                evidenceType[j] = evidenceType[j + 1];
                evidenceType[j + 1] = tmp;
                tmp = statusArr[j];
                statusArr[j] = statusArr[j + 1];
                statusArr[j + 1] = tmp;
                tmp = dateAdded[j];
                dateAdded[j] = dateAdded[j + 1];
                dateAdded[j + 1] = tmp;
                tmp = description[j];
                description[j] = description[j + 1];
                description[j + 1] = tmp;
                tmp = officerName[j];
                officerName[j] = officerName[j + 1];
                officerName[j + 1] = tmp;
            }
        }
    }

    cout << "  [OK] Records sorted by date." << endl;
    addHistory("SORT", "Records sorted by date");
    viewAllEvidence(); // Show sorted results immediately
}

// ----------------------------------------------------------------
//   sortByCaseNo()   [ Admin Option 7 ]
//   Same structure as sortByDate() but uses caseNo as the key.
//   PERMANENT — modifies the main arrays.
//   Shows sorted output via viewAllEvidence() when done.
// ----------------------------------------------------------------
void sortByCaseNo()
{
    clrscr();
    printBanner();
    cout << "  |  [^]  SORT RECORDS BY CASE NUMBER  (permanent)             |" << endl;
    printLine();
    cout << "  1.  Ascending  (A to Z)" << endl;
    cout << "  2.  Descending (Z to A)" << endl;
    cout << "  Choice : ";
    int order;
    cin >> order;

    // Bubble sort keyed on caseNo instead of dateAdded
    for (int i = 0; i < totalRecords - 1; i++)
    {
        for (int j = 0; j < totalRecords - i - 1; j++)
        {
            bool doSwap = false;
            if (order == 1 && caseNo[j] > caseNo[j + 1])
                doSwap = true;
            if (order == 2 && caseNo[j] < caseNo[j + 1])
                doSwap = true;

            if (doSwap)
            {
                // Swap all 7 arrays in sync to keep records consistent
                string tmp;
                tmp = evidenceID[j];
                evidenceID[j] = evidenceID[j + 1];
                evidenceID[j + 1] = tmp;
                tmp = caseNo[j];
                caseNo[j] = caseNo[j + 1];
                caseNo[j + 1] = tmp;
                tmp = evidenceType[j];
                evidenceType[j] = evidenceType[j + 1];
                evidenceType[j + 1] = tmp;
                tmp = statusArr[j];
                statusArr[j] = statusArr[j + 1];
                statusArr[j + 1] = tmp;
                tmp = dateAdded[j];
                dateAdded[j] = dateAdded[j + 1];
                dateAdded[j + 1] = tmp;
                tmp = description[j];
                description[j] = description[j + 1];
                description[j + 1] = tmp;
                tmp = officerName[j];
                officerName[j] = officerName[j + 1];
                officerName[j + 1] = tmp;
            }
        }
    }

    cout << "  [OK] Records sorted by case number." << endl;
    addHistory("SORT", "Records sorted by case number");
    viewAllEvidence(); // Show sorted results
}

// ----------------------------------------------------------------
//   viewHistoryLog()   [ Admin Option 8 / Viewer Option 8 ]
//   Prints every audit event stored in the history arrays.
//   Shared by both admin and viewer (viewer is read-only anyway).
//   Each line shows: number. [date] [action type] description
// ----------------------------------------------------------------
void viewHistoryLog()
{
    clrscr();
    printBanner();
    cout << "  |  [H]  CHANGE HISTORY LOG                                   |" << endl;
    printLine();

    // Edge case — no events have been logged yet
    if (totalHistory == 0)
    {
        cout << "  [!] No history recorded yet." << endl;
        pause();
        return;
    }

    // Print each history entry on its own numbered line
    for (int i = 0; i < totalHistory; i++)
    {
        cout << "  " << i + 1 << ".  "
             << "[" << historyDate[i] << "]  "
             << "[" << historyAction[i] << "]  "
             << historyLog[i] << endl;
    }

    printLine();
    cout << "  [H] Total audit events logged: " << totalHistory << endl;
    pause();
}

// ----------------------------------------------------------------
//   markAsClosed()   [ Admin Option 9 ]
//   Finds a record by ID and forces its status to "closed".
//   Saves the previous status and logs the change for audit.
// ----------------------------------------------------------------
void markAsClosed()
{
    clrscr();
    printBanner();
    cout << "  |  [X]  MARK EVIDENCE AS CLOSED                              |" << endl;
    printLine();

    string id;
    cout << "  Enter Evidence ID : ";
    cin >> id;

    // Find the record — if not found, stop here
    int idx = findEvidence(id);
    if (idx == -1)
    {
        cout << "  [!!] Evidence ID not found." << endl;
        pause();
        return;
    }

    // Save old status before overwriting, for the history log
    string oldStatus = statusArr[idx];
    statusArr[idx] = "closed";

    printLine();
    cout << "  [OK] Evidence " << id << " has been marked as CLOSED." << endl;
    cout << "       Previous status was: [ " << oldStatus << " ]" << endl;
    addHistory("UPDATE", "Evidence " + id + " marked closed (was: " + oldStatus + ")");
    pause();
}

// ================================================================
//   SECTION 4 : VIEWER FUNCTIONS  (Investigator — Read Only)
//   ---------------------------------------------------------------
//   Viewer can only browse and search, never modify data.
//   Some functions reuse admin functions (which are read-only ops).
//   Sort functions here use TEMP arrays — main data is untouched.
// ================================================================

// ----------------------------------------------------------------
//   viewerSearchByCaseNo()   [ Viewer Option 1 ]
//   Wrapper that calls the shared searchByCaseNo() function.
//   No data is modified — viewer is just reading.
// ----------------------------------------------------------------
void viewerSearchByCaseNo()
{
    searchByCaseNo(); // Reuses admin search — safe, read-only
}

// ----------------------------------------------------------------
//   searchByType()   [ Viewer Option 2 ]
//   Scans all records and prints those matching the given type.
//   Valid types: weapon / document / digital / other
// ----------------------------------------------------------------
void searchByType()
{
    clrscr();
    printBanner();
    cout << "  |  [?]  SEARCH BY EVIDENCE TYPE                              |" << endl;
    printLine();

    string searchType;
    cout << "  Enter type (weapon / document / digital / other) : ";
    cin >> searchType;

    // Linear scan — print every record whose type matches
    int found = 0;
    for (int i = 0; i < totalRecords; i++)
    {
        if (evidenceType[i] == searchType)
        {
            found++;
            printRecord(i);
        }
    }

    printLine();
    if (found == 0)
    {
        cout << "  [!] No records found for type: " << searchType << endl;
    }
    else
    {
        cout << "  [OK] Total matching records: " << found << endl;
    }
    pause();
}

// ----------------------------------------------------------------
//   viewOpenCases()   [ Viewer Option 3 ]
//   Filters and shows all records where status == "open".
// ----------------------------------------------------------------
void viewOpenCases()
{
    clrscr();
    printBanner();
    cout << "  |  [O]  ALL OPEN CASES                                       |" << endl;
    printLine();

    int found = 0;
    for (int i = 0; i < totalRecords; i++)
    {
        if (statusArr[i] == "open")
        { // Only print open records
            found++;
            printRecord(i);
        }
    }

    printLine();
    if (found == 0)
    {
        cout << "  [!] No open cases in the system." << endl;
    }
    else
    {
        cout << "  [O] Total open cases: " << found << endl;
    }
    pause();
}

// ----------------------------------------------------------------
//   viewClosedCases()   [ Viewer Option 4 ]
//   Filters and shows all records where status == "closed".
// ----------------------------------------------------------------
void viewClosedCases()
{
    clrscr();
    printBanner();
    cout << "  |  [C]  ALL CLOSED CASES                                     |" << endl;
    printLine();

    int found = 0;
    for (int i = 0; i < totalRecords; i++)
    {
        if (statusArr[i] == "closed")
        { // Only print closed records
            found++;
            printRecord(i);
        }
    }

    printLine();
    if (found == 0)
    {
        cout << "  [!] No closed cases in the system." << endl;
    }
    else
    {
        cout << "  [C] Total closed cases: " << found << endl;
    }
    pause();
}

// ----------------------------------------------------------------
//   viewerSortByDate()   [ Viewer Option 5 ]
//   DISPLAY-ONLY sort — copies all 7 arrays into temp arrays
//   and sorts THOSE, leaving the main global arrays unchanged.
//   User picks ascending or descending order.
//   Shows a compact summary line per record (not full detail).
// ----------------------------------------------------------------
void viewerSortByDate()
{
    clrscr();
    printBanner();
    cout << "  |  [^]  VIEW BY DATE  (display only — data unchanged)        |" << endl;
    printLine();
    cout << "  1.  Ascending  (oldest first)" << endl;
    cout << "  2.  Descending (newest first)" << endl;
    cout << "  Choice : ";
    int order;
    cin >> order;

    // --- Copy main arrays into temp local arrays ---
    // We sort these copies — the originals are NEVER modified
    string tID[100], tCase[100], tType[100], tStatus[100];
    string tDate[100], tDesc[100], tOfficer[100];

    for (int i = 0; i < totalRecords; i++)
    {
        tID[i] = evidenceID[i];
        tCase[i] = caseNo[i];
        tType[i] = evidenceType[i];
        tStatus[i] = statusArr[i];
        tDate[i] = dateAdded[i];
        tDesc[i] = description[i];
        tOfficer[i] = officerName[i];
    }

    // Bubble sort the temp arrays by tDate
    for (int i = 0; i < totalRecords - 1; i++)
    {
        for (int j = 0; j < totalRecords - i - 1; j++)
        {
            bool doSwap = false;
            if (order == 1 && tDate[j] > tDate[j + 1])
                doSwap = true;
            if (order == 2 && tDate[j] < tDate[j + 1])
                doSwap = true;

            if (doSwap)
            {
                // Swap all 7 temp arrays together to keep alignment
                string tmp;
                tmp = tID[j];
                tID[j] = tID[j + 1];
                tID[j + 1] = tmp;
                tmp = tCase[j];
                tCase[j] = tCase[j + 1];
                tCase[j + 1] = tmp;
                tmp = tType[j];
                tType[j] = tType[j + 1];
                tType[j + 1] = tmp;
                tmp = tStatus[j];
                tStatus[j] = tStatus[j + 1];
                tStatus[j + 1] = tmp;
                tmp = tDate[j];
                tDate[j] = tDate[j + 1];
                tDate[j + 1] = tmp;
                tmp = tDesc[j];
                tDesc[j] = tDesc[j + 1];
                tDesc[j + 1] = tmp;
                tmp = tOfficer[j];
                tOfficer[j] = tOfficer[j + 1];
                tOfficer[j + 1] = tmp;
            }
        }
    }

    // Display compact sorted summary — not full record boxes
    printLine();
    cout << "  #    Date           ID             Case          Status" << endl;
    printLine();
    for (int i = 0; i < totalRecords; i++)
    {
        cout << "  " << i + 1 << ".   "
             << tDate[i] << "   "
             << tID[i] << "   Case: "
             << tCase[i] << "   ["
             << tStatus[i] << "]" << endl;
    }
    pause();
}

// ----------------------------------------------------------------
//   viewerSortByType()   [ Viewer Option 6 ]
//   DISPLAY-ONLY sort — same temp-array approach as above,
//   but sorted alphabetically by evidence type field.
//   Main arrays remain unchanged throughout.
// ----------------------------------------------------------------
void viewerSortByType()
{
    clrscr();
    printBanner();
    cout << "  |  [^]  VIEW BY TYPE  (display only — data unchanged)        |" << endl;
    printLine();

    // Copy main arrays into temp arrays — originals stay intact
    string tID[100], tCase[100], tType[100], tStatus[100];
    string tDate[100], tDesc[100], tOfficer[100];

    for (int i = 0; i < totalRecords; i++)
    {
        tID[i] = evidenceID[i];
        tCase[i] = caseNo[i];
        tType[i] = evidenceType[i];
        tStatus[i] = statusArr[i];
        tDate[i] = dateAdded[i];
        tDesc[i] = description[i];
        tOfficer[i] = officerName[i];
    }

    // Bubble sort temp arrays alphabetically by tType
    for (int i = 0; i < totalRecords - 1; i++)
    {
        for (int j = 0; j < totalRecords - i - 1; j++)
        {
            if (tType[j] > tType[j + 1])
            {
                // Swap all 7 temp arrays to keep alignment
                string tmp;
                tmp = tID[j];
                tID[j] = tID[j + 1];
                tID[j + 1] = tmp;
                tmp = tCase[j];
                tCase[j] = tCase[j + 1];
                tCase[j + 1] = tmp;
                tmp = tType[j];
                tType[j] = tType[j + 1];
                tType[j + 1] = tmp;
                tmp = tStatus[j];
                tStatus[j] = tStatus[j + 1];
                tStatus[j + 1] = tmp;
                tmp = tDate[j];
                tDate[j] = tDate[j + 1];
                tDate[j + 1] = tmp;
                tmp = tDesc[j];
                tDesc[j] = tDesc[j + 1];
                tDesc[j + 1] = tmp;
                tmp = tOfficer[j];
                tOfficer[j] = tOfficer[j + 1];
                tOfficer[j + 1] = tmp;
            }
        }
    }

    // Display compact sorted summary by type
    printLine();
    cout << "  #    Type           ID             Case" << endl;
    printLine();
    for (int i = 0; i < totalRecords; i++)
    {
        cout << "  " << i + 1 << ".   "
             << tType[i] << "   "
             << tID[i] << "   Case: "
             << tCase[i] << endl;
    }
    pause();
}

// ----------------------------------------------------------------
//   viewOneRecord()   [ Viewer Option 7 ]
//   Lets the viewer look up a specific evidence record by ID
//   and see all its details in the full boxed printRecord format.
// ----------------------------------------------------------------
void viewOneRecord()
{
    clrscr();
    printBanner();
    cout << "  |  [=]  VIEW ONE EVIDENCE RECORD                             |" << endl;
    printLine();

    string id;
    cout << "  Enter Evidence ID : ";
    cin >> id;

    // Search for the record by ID
    int idx = findEvidence(id);
    if (idx == -1)
    {
        cout << "  [!!] Evidence ID not found." << endl;
        pause();
        return;
    }

    // Display the full boxed record
    printRecord(idx);
    pause();
}

// ----------------------------------------------------------------
//   viewerViewHistory()   [ Viewer Option 8 ]
//   Wrapper that calls viewHistoryLog() — viewer gets read-only
//   access to the same audit history as admin.
// ----------------------------------------------------------------
void viewerViewHistory()
{
    viewHistoryLog(); // Read-only — no data changed
}

// ----------------------------------------------------------------
//   filterByDateRange()   [ Viewer Option 9 ]
//   Shows all records whose dateAdded falls between two dates.
//   Date comparison works as string comparison for DD/MM/YYYY
//   as long as all dates are entered in the same format.
// ----------------------------------------------------------------
void filterByDateRange()
{
    clrscr();
    printBanner();
    cout << "  |  [#]  FILTER BY DATE RANGE                                 |" << endl;
    printLine();

    string startDate, endDate;
    cout << "  Enter start date (DD/MM/YYYY) : ";
    cin >> startDate;
    cout << "  Enter end date   (DD/MM/YYYY) : ";
    cin >> endDate;

    // Scan all records — print only those within the date range
    int found = 0;
    for (int i = 0; i < totalRecords; i++)
    {
        // String comparison works correctly for consistent DD/MM/YYYY input
        if (dateAdded[i] >= startDate && dateAdded[i] <= endDate)
        {
            found++;
            printRecord(i);
        }
    }

    printLine();
    if (found == 0)
    {
        cout << "  [!] No records found between " << startDate << " and " << endDate << endl;
    }
    else
    {
        cout << "  [#] Total records in range: " << found << endl;
    }
    pause();
}

// ================================================================
//   SECTION 5 : MENU SCREENS
//   ---------------------------------------------------------------
//   viewerMenu() — Investigator menu loop (read-only access)
//   adminMenu()  — Officer menu loop (full access, password gated)
//   main()       — Entry point and role selection screen
// ================================================================

// ----------------------------------------------------------------
//   viewerMenu()
//   Shows the Investigator menu in a loop until user logs out.
//   All options here are read-only — no data is ever modified.
// ----------------------------------------------------------------
void viewerMenu()
{
    int choice = 0;

    // Keep showing the menu until investigator picks logout (10)
    while (choice != 10)
    {
        clrscr();
        printBanner();
        cout << "  |  VIEWER MENU  --  Investigator Access                      |" << endl;
        printLine();
        cout << "  |   1.   Search by case number                               |" << endl;
        cout << "  |   2.   Search by evidence type                             |" << endl;
        cout << "  |   3.   View all open cases                                 |" << endl;
        cout << "  |   4.   View all closed cases                               |" << endl;
        cout << "  |   5.   Sort and view by date     (display only)            |" << endl;
        cout << "  |   6.   Sort and view by type     (display only)            |" << endl;
        cout << "  |   7.   View one record by ID                               |" << endl;
        cout << "  |   8.   View history log                                    |" << endl;
        cout << "  |   9.   Filter by date range                                |" << endl;
        printLine();
        cout << "  |  10.   Logout                                              |" << endl;
        printThickLine();
        cout << "  Enter choice : ";
        cin >> choice;

        // Route each choice to its matching viewer function
        if (choice == 1)
            viewerSearchByCaseNo();
        else if (choice == 2)
            searchByType();
        else if (choice == 3)
            viewOpenCases();
        else if (choice == 4)
            viewClosedCases();
        else if (choice == 5)
            viewerSortByDate();
        else if (choice == 6)
            viewerSortByType();
        else if (choice == 7)
            viewOneRecord();
        else if (choice == 8)
            viewerViewHistory();
        else if (choice == 9)
            filterByDateRange();
        else if (choice == 10)
        {
            // Logout — show goodbye message then exit the while loop
            clrscr();
            printBanner();
            cout << "  [--] Session ended. Goodbye, Investigator!" << endl;
            pause();
        }
        else
        {
            // User typed a number outside 1-10
            cout << "  [!] Invalid choice. Please enter a number from 1 to 10." << endl;
            pause();
        }
    }
}

// ----------------------------------------------------------------
//   adminMenu()
//   Password-gates entry, then shows the Admin menu in a loop.
//   Full read + write access to all evidence data.
// ----------------------------------------------------------------
void adminMenu()
{
    clrscr();
    printBanner();
    cout << "  |  ADMIN LOGIN  --  Police Officer Access                    |" << endl;
    printLine();

    // --- Password authentication ---
    string password;
    cout << "  Enter Admin Password : ";
    cin >> password;

    // Wrong password — deny access and return to main login screen
    if (password != "police123")
    {
        cout << "  [!!] Incorrect password. Access denied." << endl;
        pause();
        return; // Exit back to main() role selection
    }

    cout << "  [OK] Password accepted. Welcome, Officer." << endl;

    int choice = 0;

    // Keep showing the admin menu until officer picks logout (10)
    while (choice != 10)
    {
        clrscr();
        printBanner();
        cout << "  |  ADMIN MENU  --  Police Officer Access                     |" << endl;
        printLine();
        cout << "  |   1.   Add new evidence record                             |" << endl;
        cout << "  |   2.   Delete evidence by ID                               |" << endl;
        cout << "  |   3.   Update evidence status                              |" << endl;
        cout << "  |   4.   Search by case number                               |" << endl;
        cout << "  |   5.   View all evidence records                           |" << endl;
        cout << "  |   6.   Sort by date              (permanent)               |" << endl;
        cout << "  |   7.   Sort by case number       (permanent)               |" << endl;
        cout << "  |   8.   View change history log                             |" << endl;
        cout << "  |   9.   Mark evidence as closed                             |" << endl;
        printLine();
        cout << "  |  10.   Logout                                              |" << endl;
        printThickLine();
        cout << "  Enter choice : ";
        cin >> choice;

        // Route each choice to its matching admin function
        if (choice == 1)
            addEvidence();
        else if (choice == 2)
            deleteEvidence();
        else if (choice == 3)
            updateStatus();
        else if (choice == 4)
            searchByCaseNo();
        else if (choice == 5)
            viewAllEvidence();
        else if (choice == 6)
            sortByDate();
        else if (choice == 7)
            sortByCaseNo();
        else if (choice == 8)
            viewHistoryLog();
        else if (choice == 9)
            markAsClosed();
        else if (choice == 10)
        {
            // Logout — clean goodbye message then exit while loop
            clrscr();
            printBanner();
            cout << "  [--] Session ended. Goodbye, Officer!" << endl;
            pause();
        }
        else
        {
            // Invalid input
            cout << "  [!] Invalid choice. Please enter a number from 1 to 10." << endl;
            pause();
        }
    }
}

// ================================================================
//   SECTION 6 : MAIN — PROGRAM ENTRY POINT
//   ---------------------------------------------------------------
//   Displays the role selection screen in a loop.
//   User picks Admin (1), Viewer (2), or Exit (3).
//   The outer loop ends only when the user selects Exit.
// ================================================================
int main()
{
    int role = 0;

    // Outer loop — keeps showing the login screen until user exits (3)
    while (role != 3)
    {
        clrscr();

        // --- Main welcome banner with full decorative box ---
        cout << endl;
        cout << "  +============================================================+" << endl;
        cout << "  |                                                            |" << endl;
        cout << "  |       C R I M E   E V I D E N C E   S Y S T E M            |" << endl;
        cout << "  |                  v2.0  |  Secure Access                    |" << endl;
        cout << "  |                                                            |" << endl;
        cout << "  +============================================================+" << endl;
        cout << "  |   Authorized Personnel Only  |  All Actions Are Logged     |" << endl;
        cout << "  +------------------------------------------------------------+" << endl;
        cout << "  |                                                            |" << endl;
        cout << "  |    1.   Admin Login    (Police Officer — Full Access)      |" << endl;
        cout << "  |    2.   Viewer Login   (Investigator  — Read Only)         |" << endl;
        cout << "  |                                                            |" << endl;
        cout << "  +------------------------------------------------------------+" << endl;
        cout << "  |    3.   Exit Program                                       |" << endl;
        cout << "  +============================================================+" << endl;
        cout << endl;
        cout << "  Enter choice : ";
        cin >> role;

        // Route to the correct section based on chosen role
        if (role == 1)
            adminMenu(); // Full access — password protected inside
        else if (role == 2)
            viewerMenu(); // Read-only investigator access
        else if (role == 3)
        {
            // Clean shutdown message
            clrscr();
            cout << endl;
            cout << "  +============================================================+" << endl;
            cout << "  |   System shut down. Stay safe, Officer. Goodbye!           |" << endl;
            cout << "  +============================================================+" << endl;
            cout << endl;
        }
        else
        {
            // User typed something other than 1, 2, or 3
            cout << "  [!] Invalid choice. Please enter 1, 2, or 3." << endl;
            pause();
        }
    }

    return 0; // Program exits cleanly — OS reclaims all memory
}