C-library-for-Pushbullet
========================

Allows an easy way to implement the pushbullet api into your C programs.
This library could not be possible without the amazing API from pushbullet https://www.pushbullet.com/

With this library you will be able to easily add pushbullet support to your C programs with two easy commands, "setup()", and "push()".

This library was thrown together quite quickly for use in a project and a lot of features are yet to work. 

WORKING FEATURES

At the moment you are only able to push a 'note' to your devices.

INSTALLATION 

To use you only need to include the push.h library in your program and have push.h in your program folder.

USUAGE

Before you can push you must call setup().
When then call push(char type, char title, char body). 

Example;

-int main()
-
-{
-
-	setup();
-	
-	push("note", "This is the title","This is the message body");
-	
-}

COMMUNITY

We would love your help to clean up our code and help us include additional features
Upcoming Features

	- Able to send any type of notification,
	
		-URL
		
		-FILE
	
	- Push to friends devices.

CONTRIBUTIONS

Carl A. Neuhaus

Simon G. Ralph
