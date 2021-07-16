# Exit script after first failure
set -e 
set -o pipefail

echo "Cleanup building directory..."
rm -R ../build/Release

echo "Entering on building directory..."
mkdir ../build/Release
cd ../build/Release


echo "Executing cmake to create makefile project..."
cmake ../../ -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release

echo "Start building..."
#make
cmake --build .


echo "Clean up depoyment directory..."
rm -R ../build/Deployment/linux

echo "Create directory build/Deploy/linux"
mkdir ../build/Deployment/linux

echo "[success] Build file copied to output: build/Deploy/linux/"
