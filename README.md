# ATM-SYSTEM


#### Description

Welcome to the **ATM Management System**, a console-based application designed to manage user accounts and facilitate various banking operations. This project is built using C++ and allows both administrators and users to perform actions like adding new users, viewing account details, depositing and withdrawing money, and updating personal information securely.

### Features

#### Admin Features:
1. **Add User**: Admins can create new user accounts with a unique PIN.
2. **Delete User**: Remove user accounts from the system.
3. **View All Users**: Display all registered users with their account details.
4. **Search Specific User**: Find specific user details by entering the user's name and PIN.

#### User Features:
1. **Show My Data**: View your account details including name, PIN, and balance.
2. **Deposit Money**: Add money to your account.
3. **Withdraw Money**: Withdraw money from your account, with checks for sufficient balance.
4. **Update PIN**: Change your account's PIN for security.

### How It Works

The application uses file handling to store and manage user data. Each user's information, including name, PIN, and balance, is stored in a text file (`ATMFILE.txt`). Admins can modify this data by adding or deleting user accounts, while users can interact with their accounts through the system's interface.

#### Classes and Methods:

- **Class `user`**:
  - *Attributes*: Name, PIN, balance
  - *Methods*: `Names()`, `getbal()`, `setbal()`, `setpass()`, `PINs()`, `showData()`, `deposit()`, `withdraw()`, `getData()`, `showmydata()`, `UPDATEPIN()`

- **Class `admin`** (inherits from `user`):
  - *Methods*: `add_new_user()`, `all_data()`, `deleteuser()`, `search1_user()`, `search_user()`

### Usage

To run the application, compile and execute the `main()` function. The system will prompt you to log in as either an admin or a user. Admins use a special password (`786`) to access admin functions, while users can log in using their unique name and PIN.

### File Structure

- **`ATMFILE.txt`**: The main file where user account information is stored.
- **`temp.txt`**: A temporary file used during operations like updating user data or deleting accounts.

### Important Notes

1. **Data Integrity**: The application ensures data integrity by using temporary files for updates, ensuring that the original data is only overwritten once the changes are confirmed.
2. **Security**: User information is secured with a PIN, and admin functions are protected with a master password.
3. **Error Handling**: The system includes basic error handling for common issues like file access errors and insufficient balance during withdrawals.

### Future Enhancements

- **User Authentication**: Implementing more secure methods for user authentication.
- **Improved UI**: Enhancing the user interface for better usability.
- **Database Integration**: Moving from file-based storage to a database system for better scalability and data management.

Thank you for using the  ATM Management System. Your feedback and suggestions are always welcome!
