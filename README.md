
# simple-ATM-controller

<h2>Task Requirements</h2> 
		<p>
At least the following flow should be implemented:

Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

For simplification, there are only 1 dollar bills in this world, no cents. Thus account balance can be represented in integer.

Your code doesn't need to integrate with a real bank system, but keep in mind that we may want to integrate it with a real bank system in the future. It doesn't have to integrate with a real cash bin in the ATM, but keep in mind that we'd want to integrate with that in the future. And even if we integrate it with them, we'd like to test our code. Implementing bank integration and ATM hardware like cash bin and card reader is not a scope of this task, but testing the controller part (not including bank system, cash bin etc) is within the scope.

A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not.

Based on your work, another engineer should be able to implement the user interface. You don't need to implement any REST API, RPC, network communication etc, but just functions/classes/methods, etc.

You can simplify some complex real world problems if you think it's not worth illustrating in the project.
	</p>
	
<h2>How to set up Environment</h2>
	<ol>
		<li>Install MSYS2 from msys2.org</li>
		<li>Open MSYS2 Command Prompt window and run the following code.<br>
		   <code>
			  pacman --noconfirm -Syu && pacman --noconfirm -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-clang 
		  </code>
		</li>
		<li>Install and open JetBrains CLion IDE</li>
		<li>On the <b>Configure Toolchains</b> window, click <b>MingGW</b></li>
		<li>
			For <b>Environment</b>, search and find the location of mingw64 (<code>C:\msys64\mingw64</code> by default)
		</li>
		<li>
		The rest will have been automatically configured at this point. Make sure that the <b>C++ Compiler</b> is set as <code>C:\msys64\bn\clang++.exe</code>.
		</li>
	</ol>

<h2>How to Run Tests</h2>
	<p>
		Edit the unit tests and press the green "Run" button on the top right side of the IDE, or <kbd>Shift</kbd> + <kbd>F10</kbd>. User can interact with the program via the console.
	</p>
	<h3>Usage Guide</h3>
		<ul>
			<li>
				To run the ATM in DEV mode, enter ```dev``` at the Card Number entering screen (beginning screen).
				This will allow you to access the DEV MESSAGE at the bottom of the screen for 'debugging' purposes.
			</li>
		</ul>

<h2>Environment Description</h2>
 <ul>
  <li>OS: Windows</li>
  <li>Tools: MSYS2 64bit, CMake</li>
  <li>Environment: MingW</li>
  <li>C++ Compiler: clang++.exe</li>
  <li>IDE: JetBrains CLion</li>
 </ul>

