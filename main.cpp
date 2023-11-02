#include <iostream>
#include <windows.h>
#include <curl.h>

CURL *curl;
CURLcode res;

int testWebhook(const std::string& webhookUrl) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        curl_easy_setopt(curl, CURLOPT_URL, webhookUrl.c_str());

        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if(response_code == 200) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                std::cout << "Webhook is valid!" << std::endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                curl_easy_cleanup(curl);
                curl_global_cleanup();
                return 1;
            }
            else {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout << "Webhook is invalid! [ " << response_code << " ]" << std::endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                curl_easy_cleanup(curl);
                curl_global_cleanup();
                return 0;
            }
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}

int spamWebhook(const std::string& webhookMessage, const std::string& spamAmount, const std::string& webhookUrl, const std::string& deleteAfterUse) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 1L);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
        curl_easy_setopt(curl, CURLOPT_CAPATH, "cacert.pem");

        std::string jsonPayload = "{\"content\":\"" + webhookMessage + "\"}";

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        for (int i = 0; i < std::stoi(spamAmount); ++i) {
            curl_easy_setopt(curl, CURLOPT_URL, webhookUrl.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            CURLcode res = curl_easy_perform(curl);

            if (res != CURLE_OK && res != CURLE_HTTP_RETURNED_ERROR) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }

        if (deleteAfterUse=="Y" || deleteAfterUse=="y") {
            curl_global_init(CURL_GLOBAL_ALL);

            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 1L);
                curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
                curl_easy_setopt(curl, CURLOPT_CAPATH, "cacert.pem");

                curl_easy_setopt(curl, CURLOPT_URL, webhookUrl.c_str());
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");

                res = curl_easy_perform(curl);

                if(res != CURLE_OK)
                    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 0;
    }

    return 1;
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

    std::cout << "Hello, World!" << std::endl;

    std::string webhookUrl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    std::cout << "Please enter a webhook _>" << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::getline(std::cin, webhookUrl);

    int validateWebhook = testWebhook(webhookUrl);

    if (validateWebhook == 0) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout << "Exiting..." << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return 1;
    }

    std::string webhookMessage;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    std::cout << "Please enter a message _>" << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::getline(std::cin, webhookMessage);

    std::string spamAmountStr;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    std::cout << "Please enter the amount of messages to send _>" << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::getline(std::cin, spamAmountStr);

    int spamAmount;
    try {
        spamAmount = std::stoi(spamAmountStr);
    } catch (const std::invalid_argument& e) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return 1;
    }

    std::string deleteAfterUse;

    while (true) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        std::cout << "Delete webhook after usage [ Y/N ] _>" << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::getline(std::cin, deleteAfterUse);

        if (deleteAfterUse == "Y" || deleteAfterUse == "y") {
            break;
        } else if (deleteAfterUse == "N" || deleteAfterUse == "n") {
            break;
        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            std::cout << "Invalid input. Please enter 'Y' or 'N'." << std::endl;
        }
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    std::cout << "Starting..." << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    int validateSpam = spamWebhook(webhookMessage, std::to_string(spamAmount), webhookUrl, deleteAfterUse);

    if (validateSpam == 0) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << "Were able to forward messages to webhook!" << std::endl;
    } else {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout << "Could not forward messages to webhook!" << std::endl;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return 0;
}
