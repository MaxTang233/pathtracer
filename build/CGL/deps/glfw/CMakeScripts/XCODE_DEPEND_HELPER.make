# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.glfw.Debug:
/Users/max/Desktop/cs284/p3-1-pathtracer-sp20-MaxTang233/build/CGL/deps/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/max/Desktop/cs284/p3-1-pathtracer-sp20-MaxTang233/build/CGL/deps/glfw/src/Debug/libglfw3.a


PostBuild.glfw.Release:
/Users/max/Desktop/cs284/p3-1-pathtracer-sp20-MaxTang233/build/CGL/deps/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/max/Desktop/cs284/p3-1-pathtracer-sp20-MaxTang233/build/CGL/deps/glfw/src/Release/libglfw3.a


PostBuild.glfw.MinSizeRel:
/Users/max/Desktop/cs284/p3-1-pathtracer-sp20-MaxTang233/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/max/Desktop/cs284/p3-1-pathtracer-sp20-MaxTang233/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a


PostBuild.glfw.RelWithDebInfo:
/Users/max/Desktop/cs284/p3-1-pathtracer-sp20-MaxTang233/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/max/Desktop/cs284/p3-1-pathtracer-sp20-MaxTang233/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a




# For each target create a dummy ruleso the target does not have to exist
