:: For some reason this is not working as a postbuild command
:: TODO: Fix it.

:: SDL2
xcopy PeanutButter\PeanutButter\thirdparty\SDL2-2.0.12\lib\x64\SDL2.dll bin\Debug-windows-x86_64\PBPong /f /y

:: SDL2 Image
xcopy PeanutButter\PeanutButter\thirdparty\SDL2_image-2.0.5\lib\x64\libjpeg-9.dll bin\Debug-windows-x86_64\PBPong /f /y
xcopy PeanutButter\PeanutButter\thirdparty\SDL2_image-2.0.5\lib\x64\libpng16-16.dll bin\Debug-windows-x86_64\PBPong /f /y
xcopy PeanutButter\PeanutButter\thirdparty\SDL2_image-2.0.5\lib\x64\libtiff-5.dll bin\Debug-windows-x86_64\PBPong /f /y
xcopy PeanutButter\PeanutButter\thirdparty\SDL2_image-2.0.5\lib\x64\libwebp-7.dll bin\Debug-windows-x86_64\PBPong /f /y
xcopy PeanutButter\PeanutButter\thirdparty\SDL2_image-2.0.5\lib\x64\SDL2_image.dll bin\Debug-windows-x86_64\PBPong /f /y
xcopy PeanutButter\PeanutButter\thirdparty\SDL2_image-2.0.5\lib\x64\zlib1.dll bin\Debug-windows-x86_64\PBPong /f /y

:: SDL2 TTF
xcopy PeanutButter\PeanutButter\thirdparty\SDL2_ttf-2.0.15\lib\x64\libfreetype-6.dll bin\Debug-windows-x86_64\PBPong /f /y
xcopy PeanutButter\PeanutButter\thirdparty\SDL2_ttf-2.0.15\lib\x64\SDL2_ttf.dll bin\Debug-windows-x86_64\PBPong /f /y
PAUSE