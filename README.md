<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Projects Repository</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
            color: #333;
        }

        .container {
            width: 80%;
            margin: auto;
            overflow: hidden;
        }

        header {
            background: #333;
            color: #fff;
            padding-top: 30px;
            min-height: 70px;
            border-bottom: #0779e4 3px solid;
        }

        header a {
            color: #fff;
            text-decoration: none;
            text-transform: uppercase;
            font-size: 16px;
        }

        header ul {
            padding: 0;
            list-style: none;
        }

        header li {
            display: inline;
            padding: 0 20px 0 20px;
        }

        .showcase {
            min-height: 400px;
            background: #0779e4;
            color: #fff;
            text-align: center;
            padding-top: 100px;
        }

        .showcase h1 {
            font-size: 55px;
            margin-top: 0;
            margin-bottom: 10px;
        }

        .showcase p {
            font-size: 20px;
        }

        .content {
            padding: 20px;
            background: #fff;
            margin-top: 20px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }

        .content h2 {
            color: #0779e4;
        }

        .projects ul {
            list-style: none;
            padding: 0;
        }

        .projects li {
            background: #e2e2e2;
            margin: 10px 0;
            padding: 10px;
            border-left: #0779e4 5px solid;
        }

        .projects li h3 {
            margin: 0;
        }
    </style>
</head>

<body>
    <header>
        <div class="container">
            <h1>My Problem Solving Repository</h1>
            <ul>
                <li><a href="#about">About</a></li>
                <li><a href="#projects">Projects</a></li>
                <li><a href="#games">Games</a></li>
            </ul>
        </div>
    </header>

    <section class="showcase">
        <div class="container">
            <h1>Welcome to My GitHub Repository</h1>
            <p>Explore my problem-solving projects and games developed using various programming languages.</p>
        </div>
    </section>

    <div class="container">
        <section class="content" id="about">
            <h2>About</h2>
            <p>This repository contains a collection of my problem-solving projects and games. I've worked on various
                JavaScript projects, developed games in C and C++, and continually strive to improve my programming
                skills.</p>
        </section>

        <section class="content" id="projects">
            <h2>Projects</h2>
            <div class="projects">
                <ul>
                    <li>
                        <h3>Basic JavaScript Projects</h3>
                        <p>A collection of basic projects developed using JavaScript, including form validations, dynamic
                            UI updates, and simple interactive applications.</p>
                    </li>
                </ul>
            </div>
        </section>

        <section class="content" id="games">
            <h2>Games</h2>
            <div class="projects">
                <ul>
                    <li>
                        <h3>Snake Xenzia</h3>
                        <p>An exciting snake game developed in C, reminiscent of the classic mobile game Snake Xenzia.</p>
                    </li>
                    <li>
                        <h3>Racing Game</h3>
                        <p>A thrilling racing game developed in C++, where players can experience high-speed races with
                            challenging tracks.</p>
                    </li>
                </ul>
            </div>
        </section>
    </div>
</body>

</html>
