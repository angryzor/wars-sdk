#pragma once

namespace app
{
	class GameManager;
}

namespace hh::fnd
{
	class Messenger
	{
	protected:
		/*
		 * Sends a message to one particular receiver.
		 */
		Message* SendMessage(Handle<Messenger>& receiver, Message& message);
		bool SendMessageImm(Handle<Messenger>& receiver, Message& message);
		bool ForwardMessageImm(Handle<Messenger>& receiver, Message& message);

		/*
		 * Send a fully built message.
		 */
		Message* SendMessage(Message& message);

	public:
		MessageManager* messageManager;
		uint32_t messageMask;
		uint32_t unk3;

		Messenger();

		virtual ~Messenger();
		virtual bool ProcessMessage(Message& message) { return !fUnk3(); }
		virtual bool fUnk3() { return false; }
		virtual bool ReceiveMessage(Message& message);
		
		// Send message to this messenger (fixme: rename to SendMessageImmTo or something...)
		bool SendMessageImm(Message& message);
	};
}
