**Summarize the project and what problem it was solving.**

I was tasked with creating a program that allows younger users to explore the idea of compound interest. The program asks the user to input amounts for their projected savings, such as monthly deposits, initial deposits, and the amount of interest. It then shows them two tables; one with the monthly deposits included, and one without. Having the tables display next to eachother helps put into perspective the power of compound interest.

**What did you do particularly well?**

I think I did particularly well in the formatting and looping of the menu. It took me a while but was happy with how the results turned out. I was also happy with the input validation, this was a tricky one that required some digging through the C++ documentation before being happy with the result. In the early stages of development, my validation only included checks for incorrect numbers. The program would break when words or incorrect types were submitted, so I wanted to make sure that this did not happen in the final result.
  
**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**

One area I know I could enhance my code could be with portability. To clear the screen I used a function specific to windows, so changing that to detect the user's operating system could allow for a wider userbase. Another way I could enhance the code is in the output, the formatting is set to specific number sizes so if a user input very large values the program would display incorrectly. These improvements would allow the program to be more user friendly and readable.
  
**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**

The piece of code I found most challenging to write was the formatting of the output tables. This took me the longest to finish, as I am sure the method of guess and check I was using was not the most efficient. I eventually overcame this after spending the time thoroughly researching the string formatting pages on the C Plus Plus documentation. I will be adding the documentation website as a staple as I continue learning C++.
  
**What skills from this project will be particularly transferable to other projects or course work?**

I think the biggest skill that will be particularly transferable to other projects are the overall code logic of using multiple files for classes. I know this is something that will be important in the future for other projects, so having a solid grasp on this concept now will be a very useful tool.
  
**How did you make this program maintainable, readable, and adaptable?**

By using separate files for the functions I was able to make the program easier to read and maintain. I could have broken it down even further if I wanted, but due to the size of the program I found it best to keep it in one class file. If I were to add more features to the program, I would certainly break each feature into their own file, saving me compile time when I only need to change one function.
