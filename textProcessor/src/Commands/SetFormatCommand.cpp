#include "../../headers/Commands/SetFormatCommand.hpp"


/**
 * @file SetFormatCommand.cpp
 * @author MK
 * @brief A command to set the active formatter in the text processor application.
 */


 /**
  * @brief Constructor for the SetFormatCommand class.
  */
 SetFormatCommand::SetFormatCommand(SetFormatCommandCLI* cli, ActiveFormatter* activeFormatter) {
    this->cli = cli;
    this->activeFormatter = activeFormatter;
 }


 /**
  * @brief gets the name of the command.
  */
 string SetFormatCommand::getName() const {
    return SET_FORMAT_COMMAND_NAME;
 }

 /**
  * @brief execute the command to set the active formatter.
  * This method retrieves the formatter type from the CLI, saves the previous formatter type,
 * and sets the new formatter type in the ActiveFormatter instance.
  */
 void SetFormatCommand::execute() {
    string formatterType = cli->getFormatterType(activeFormatter->getActiveFormatterType());
    previousFormatterType = activeFormatter->getActiveFormatterType();
    previousFormatPoint = activeFormatter->getActiveFormatterFormatPoint();

    int formatPoint = 0;
    if (formatterType != "DirectFormatter") {
        try {
            formatPoint = cli->getFormatPoint();
        } catch (const std::runtime_error& e) {
            cli->error(e.what());
            return;
        }
    }

    try {
        activeFormatter->setFormatter(formatterType, formatPoint);
    } catch (const runtime_error& e) {
        cli->error("Failed to set formatter: " + string(e.what()));
        return;
    }
    cli->success();

 }

 /**
  * @brief Undoes the last executed command of setting the formatter.
  * This method restores the previous formatter type if it exists.
  */
 void SetFormatCommand::undo() {
    if (previousFormatterType.empty()) {
        return;
    }

    try {
        activeFormatter->setFormatter(previousFormatterType, previousFormatPoint);
    } catch (const runtime_error& e){
        cli->error("Failed to undo formatter change: " + string(e.what()));
        return;
    }

    cli->successUndo();
 }