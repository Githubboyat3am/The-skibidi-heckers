void Aimbot(HANDLE hProcess, vector<Player>& players, float yourX, float yourY, float yourZ) {
    Player closestPlayer;
    float closestDistance = FLT_MAX;

    // Loop through all players and check if they are an enemy
    for (auto& player : players) {
        if (player.teamId != 1) {  // Example: enemy team
            float distance = sqrt(pow(player.headX - yourX, 2) + pow(player.headY - yourY, 2) + pow(player.headZ - yourZ, 2));
            if (distance < closestDistance) {
                closestDistance = distance;
                closestPlayer = player;
            }
        }
    }

    // Lock on to the enemy's head by adjusting the crosshair (Memory manipulation)
    float deltaX = closestPlayer.headX - yourX;
    float deltaY = closestPlayer.headY - yourY;
    float deltaZ = closestPlayer.headZ - yourZ;

    WriteProcessMemory(hProcess, (LPVOID)0xCrosshairX, &deltaX, sizeof(deltaX), NULL);
    WriteProcessMemory(hProcess, (LPVOID)0xCrosshairY, &deltaY, sizeof(deltaY), NULL);
    WriteProcessMemory(hProcess, (LPVOID)0xCrosshairZ, &deltaZ, sizeof(deltaZ), NULL);
}
