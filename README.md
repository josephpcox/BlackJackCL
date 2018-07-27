# Authors: Joseph Cox and Mauzor Ilonzo

**Edit a file, create a new file, and clone from Bitbucket in under 2 minutes**

When you're done, you can delete the content in this README and update the file with details for others getting started with your repository.

*We recommend that you open this README in another tab as you perform the tasks below. You can [watch our video](https://youtu.be/0ocf7u76WSo) for a full demo of all the steps in this tutorial. Open the video in a new tab to avoid leaving Bitbucket.*

---
# General Overview of the Program

We have 4 classes in this Blackjack project: *Card*, *User*, *Dealer* & *Game*. The card class handles the values of the card. The User class holds a vector of cards which and keeps track of the value of the players’ bets and earnings. 

The *Dealer* class is a special *User* Class which is responsible for creating and managing the deck of cards used in the game. and also has a hand to compete with the players. The Game Class handles the basic operations of the game such as handling how the player wants to play their hand, finding who bet the dealer and paying out the players earnings. The *Game* Class is also responsible of printing displays of the player’s hands, numerical hand value, their current balance, and both the dealer’s and the user’s hand.


---

# Complier Information 

We use the gcc compiler and c++14, to install gcc on a local linux machine use: **$sudo apt-get install gcc**.

**Mac Users**

For Mac users this should prompt you to install the developer tool set which will give you the Clang compiler. You need to accept this process
to run this code.

**Linux Users** 

If the gcc compiler is not on your machine this will the above command 
should download it for you

**Windows Users** 

You will need to intall the Microsoft Visual Studios IDE from: https://visualstudio.microsoft.com/
**Note: The community edition is free**

---

# Makefile to Compile and Run for Linux and Mac 

**compile**

To compile and run the program on a Mac or Linux machine open a terminal and navigate to the project folder **$cd < REPOSITORY PATH >**. Inside the reposity path you should see a file called: *makefile* this file will compile the program for you. To compile inside the termianl use **$make** and it will generate an executable called: *blackJack*.

**Run**

The command to run our program is:
**$./blackJack**

---

# Project Details

**Operator Overloading Implementation**

In our *Card* Class we overloaded the *=*(assignment) operator in order to determine whether two given cards objects are equivalent in value. 

**Inheritance Implementation**

The *Dealer* class is publically inherited from the *User* class so that the Dealer object has its own Hand and balance while the object has access to unique functions that the User Objects should not have such as the makeDeck, which creates a 52 card deck that the game will be using.


**vector Implementation**

Our *User* class utilizes a vector of cards to represent a player’s hand and the 52 card deck that will be used in the game. We also have a vector of User objects in our main functions in order to easily implement the player’s turnover.

**Const Implementation**

Throughout our classes we often used *const* in get-functions in order to prevent the function from tampering with the data members inside the class

**static Implementation**

A *static unsigned int* variable called *round* was implemented in our Game Class. This variable serves to count how many rounds of Blackjack have transpired in this program’s duration.


---

## Edit a file

You’ll start by editing this README file to learn how to edit a file in Bitbucket.

1. Click **Source** on the left side.
2. Click the README.md link from the list of files.
3. Click the **Edit** button.
4. Delete the following text: *Delete this line to make a change to the README from Bitbucket.*
5. After making your change, click **Commit** and then **Commit** again in the dialog. The commit page will open and you’ll see the change you just made.
6. Go back to the **Source** page.

---

## Create a file

Next, you’ll add a new file to this repository.

1. Click the **New file** button at the top of the **Source** page.
2. Give the file a filename of **contributors.txt**.
3. Enter your name in the empty file space.
4. Click **Commit** and then **Commit** again in the dialog.
5. Go back to the **Source** page.

Before you move on, go ahead and explore the repository. You've already seen the **Source** page, but check out the **Commits**, **Branches**, and **Settings** pages.

---

## Clone a repository

Use these steps to clone from SourceTree, our client for using the repository command-line free. Cloning allows you to work on your files locally. If you don't yet have SourceTree, [download and install first](https://www.sourcetreeapp.com/). If you prefer to clone from the command line, see [Clone a repository](https://confluence.atlassian.com/x/4whODQ).

1. You’ll see the clone button under the **Source** heading. Click that button.
2. Now click **Check out in SourceTree**. You may need to create a SourceTree account or log in.
3. When you see the **Clone New** dialog in SourceTree, update the destination path and name if you’d like to and then click **Clone**.
4. Open the directory you just created to see your repository’s files.

Now that you're more familiar with your Bitbucket repository, go ahead and add a new file locally. You can [push your change back to Bitbucket with SourceTree](https://confluence.atlassian.com/x/iqyBMg), or you can [add, commit,](https://confluence.atlassian.com/x/8QhODQ) and [push from the command line](https://confluence.atlassian.com/x/NQ0zDQ).

---

