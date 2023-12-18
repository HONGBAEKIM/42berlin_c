# hong42





a) What is the RFC Telnet document about?
Request for Comments (RFC) is document that describes the specifications for a recommended technology

TELNET PROTOCOL SPECIFICATION https://datatracker.ietf.org/doc/html/rfc854


b) What does NGINX do? (Proxyserver, see project Inception)
NGINX is open-source web server software used for reverse proxy, load balancing, and caching. It provides HTTPS server capabilities and is mainly designed for maximum performance and stability. 

https://www.papertrail.com/solution/guides/nginx/


c) What are accepted HTTP methods? 
POST, GET, PUT, PATCH, and DELETE
https://doc.oroinc.com/api/http-methods/

What is a HTTP redirection?
URL redirection is a technique to give more than one URL address to a page, a form, a whole website, or a web application. 
https://developer.mozilla.org/en-US/docs/Web/HTTP/Redirections

d) What is a chunked request? 
A type of data transfer in which information is sent in discrete chunks instead of a single, continuous stream

chunking is how you transfer a block of data


How does chunked encoding work?

https://bunny.net/academy/http/what-is-chunked-encoding/


<The client can be bounced properly if necessary.
-from evaluation sheet- >
What does it mean to "bounce" from a above sentence?
if there are issues or problems with the client, it should be possible to restart or reset the client without causing disruptions to the overall system.




1) What are the basics of an HTTP server?
An HTTP server is software that understands URLs (web addresses) and HTTP (the protocol your browser uses to view webpages). 
https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Web_mechanics/What_is_a_web_server

2) What is I/O multiplexing? 
I/O multiplexing is typically used in networking applications in the following scenarios:

* When a client is handling multiple descriptors (normally interactive input and a network socket)
* When a client to handle multiple sockets at the same time (this is possible, but rare)
* If a TCP server handles both a listening socket and its connected sockets
* If a server handles both TCP and UDP
* If a server handles multiple services and perhaps multiple protocols

https://notes.shichao.io/unp/ch6/


How do we handle I/O multiplexing?

-Create and Configure File Descriptors:

* Open sockets or file descriptors for the I/O operations you want to monitor.
* Set non-blocking mode on these file descriptors to avoid blocking issues.

-Use I/O Multiplexing System Calls:

* Call the appropriate system call (select(), poll(), epoll(), etc.) to monitor multiple file descriptors for activity.
* The system call will block until any of the file descriptors are ready for I/O operations or until a specified timeout occurs.


3) What do select() / poll() / kqueue() / epoll() do?
select():
Monitors multiple file descriptors for read, write, or exception events.
Blocks until any of the file descriptors are ready or a timeout occurs.
The application must repeatedly call select() to check for events.

poll():
Similar to select() but generally considered more scalable.
Monitors multiple file descriptors for read, write, or exception events.
Blocks until any of the file descriptors are ready or a timeout occurs.
More efficient than select() for a large number of file descriptors.

kqueue():
Monitors multiple file descriptors for various events.
Provides a scalable and efficient I/O notification mechanism.
Allows monitoring for a variety of events beyond traditional socket events.
Suitable for high-performance applications.

epoll():
Monitors multiple file descriptors for read, write, or error events.
Considered highly scalable and efficient, especially for a large number of file descriptors.
Supports edge-triggered and level-triggered modes.


4) What are the HTTP response status codes?

Informational responses (100–199):

* 100 Continue: The server has received the initial part of the request and will continue processing.

Successful responses (200–299):

* 200 OK: The request was successful, and the server has returned the requested data.
* 201 Created: The request has been fulfilled, and a new resource has been created as a result.
* 204 No Content: The server successfully processed the request but does not need to return any content.

Redirection messages (300–399):

* 301 Moved Permanently: The requested resource has been permanently moved to a new location.
* 302 Found (or Temporary Redirect): The requested resource has been temporarily moved to another location.
* 304 Not Modified: The client's cached copy is still valid, and the server did not send a new representation.

Client error responses (400–499):

* 400 Bad Request: The server cannot process the request due to a client error.
* 401 Unauthorized: Authentication is required, and the client needs to provide valid credentials.
* 403 Forbidden: The client does not have permission to access the requested resource.
* 404 Not Found: The requested resource could not be found on the server.

Server error responses (500–599):

* 500 Internal Server Error: A generic error message indicating that the server encountered an unexpected condition.
* 501 Not Implemented: The server does not support the functionality required to fulfill the request.
* 503 Service Unavailable: The server is temporarily unable to handle the request due to maintenance or overloading.



5) What are GET, POST and DELETE on the server?

1. GET:

    * Purpose: Retrieves data from the server.
    * Characteristics:
        * Requests are appended to the URL as parameters.
        * Information is visible in the URL.
        * Generally used for read-only operations.
        * Caching of responses is common.
        * Idempotent: Repeated identical requests have the same effect as a single request.

Example:

bash
Copy code
GET /api/users?id=123

1. POST:

    * Purpose: Submits data to be processed to a specified resource.
    * Characteristics:
        * Requests can include a message body.
        * Data is not appended to the URL.
        * Suitable for creating new resources or submitting data for processing.
        * Not idempotent: Repeated identical requests might have different effects.
        * Responses are typically not cached.

Example:

bash
Copy code
POST /api/users
{
    "name": "John Doe",
    "email": "john@example.com"
}

1. DELETE:

    * Purpose: Requests that a resource be removed or deleted.
    * Characteristics:
        * Typically used to delete a resource identified by a URL.
        * Requests may include a message body, but it is rarely used.
        * Idempotent: Repeated identical requests have the same effect as a single request.
        * Responses are typically not cached.

Example:

bash
Copy code
DELETE /api/users/123


6) How to handle UNKNOWN server requests?
When your server receives an UNKNOWN request, it's essential to have a default response that informs the client that the request is not recognized or understood. This can be an HTTP status code like 400 (Bad Request) or 404 (Not Found) with an appropriate error message.

7) What is Common Gateway Interface?
CGI, is a standard protocol for enabling communication between web servers and external programs or scripts.

1.Server-Script Interaction: CGI acts as a bridge between the web server and external scripts or programs written in languages such as Perl, Python, C, or other scripting and programming languages. When a client requests a CGI script, the web server invokes the script, passes along the client's request information (e.g., HTTP headers, query parameters), and allows the script to generate dynamic content.

2.HTTP Request Handling: CGI scripts can handle different types of HTTP requests, such as GET and POST. They can extract data from request parameters, process it, and generate appropriate HTTP responses.

3.Output Generation: CGI scripts generate HTML, XML, or other content that is sent back to the client's browser. This generated content is typically used to dynamically produce web pages, process form submissions, or perform various server-side tasks.

4.Separation of Concerns: CGI separates the web server's core functionality from application logic. This separation allows developers to write server-side code in a variety of programming languages and run it on the web server without modifying the server software itself.

5.Environmental Variables: CGI scripts have access to environment variables that contain information about the client's request, server configuration, and runtime environment. These variables are useful for customizing script behavior.

6.Security Considerations: Proper security measures must be taken when using CGI to prevent security vulnerabilities, such as code injection attacks or unauthorized access to sensitive data. Input validation and sanitization are critical to mitigate these risks.

7.Performance: CGI has been largely replaced by more efficient and scalable technologies for dynamic web content generation, such as server-side scripting frameworks (e.g., PHP, Ruby on Rails), application servers (e.g., Tomcat, Node.js), and FastCGI. These alternatives are often preferred for high-performance web applications.

8) Pick a supported browser to use for this project!

9) What is a fully static website?
static website, is a type of website where all the web pages are pre-generated and served to visitors exactly as they were initially created. 

10) What is Siege and how do we use it for testing our server?

Siege is an open-source command-line tool used for load testing and stress testing web servers and web applications. It allows you to simulate multiple concurrent users making HTTP requests to your server, helping you assess how well your server or website performs under various levels of traffic and load.

11) How do we get a 99.5% availability with the command siege -b?
In Siege, achieving a 99.5% availability with the -b (benchmarking) option involves configuring the tool to simulate user load on your server while monitoring the availability of your web application.

12) What are "hanging" connections?
"Hanging" connections, refer to connections that have been established between a client and a server but are in a state of limbo or idle without actively transmitting data.

