void ESP(HANDLE hProcess, vector<Player>& players) {
    for (auto& player : players) {
        if (player.health > 0) {
            // Convert 3D world coordinates to 2D screen coordinates (this needs to be implemented with DirectX or OpenGL)
            float screenX, screenY;
            WorldToScreen(player.headX, player.headY, player.headZ, screenX, screenY);

            // Draw a box around the enemy (You need to implement rendering with DirectX/Direct2D)
            DrawBox(screenX, screenY);
        }
    }
}
