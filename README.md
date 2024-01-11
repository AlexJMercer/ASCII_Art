# ASCII Art

> - In `camera.cpp`, the objective was to first test if the built in camera works properly.
>
> - As I found out, the default webcam (in my case, my laptop's webcam) is NOT accessible by default if you create a `Docker` container and build your C++ file in it.
>
> - As a result, I had to move to Visual Studio to get rid of such hiccups.

## Webcam to ASCII
>
> ![image](https://github.com/AlexJMercer/ASCII_Art/assets/55972469/7a965b7e-68dc-41ef-bcb4-180bfaa05f21)
>
> The idea is to take a video input stream from the deafult webcam, and then translate each pixel into an ASCII character depending on it's `brightness` value.
>
> The `brightness` or `intensity` is calculated as a `mean` of the R, G and B values of each pixel.
>
> Each frame is thus encoded into a string of these characters and then printed into the terminal.
>
> I played around with the string of characters that the brightness depends on, and figured it looks best when the shadows and highlights are "muted", i.e, having light characters.
>
> Feel free to suggest improvements, hopefully I can make run a lot faster as I haven't implemented multi-threading on this !
>
