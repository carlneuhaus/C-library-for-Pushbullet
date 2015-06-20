C-library-for-Pushbullet
========================

Allows an easy way to implement the pushbullet api into your C programs.
This library could not be possible without the amazing API from pushbullet https://www.pushbullet.com/

With this library you will be able to easily add pushbullet support to your C programs with two easy commands, "setup()", and "push()".

This library was thrown together quite quickly for use in a project and a lot of features are yet to work. 

**WORKING FEATURES**

You are able to send links, address and notes at the moment.  

**INSTALLATION**

To use you only need to include the push.h library in your program and have push.h in your program folder.

You must create a free pushbullet account and note down your API number.

**USAGE**

Before you can push you must call setup().
When then call push(char type, char title, char body). 

**Example;**

	#include "push.h"
	
	int main()

	{

	setup();

	push("note", "This is the title","This is the message body");
	
	}

**COMMUNITY**

We would love your help to clean up our code and help us include additional features
Upcoming Features

	- Able to send any type of notification,
		
		-FILE etc
	
	- Push to friends devices.
		- Friends devices do not show up in the api call. 		not sure if this is a problem on our end or the 		api's end.

**CONTRIBUTIONS**

Carl

Simon
