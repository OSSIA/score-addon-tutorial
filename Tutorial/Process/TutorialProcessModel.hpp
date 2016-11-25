#pragma once
#include <Process/Process.hpp>

namespace Tutorial
{
class ProcessModel final : public Process::ProcessModel
{
        ISCORE_SERIALIZE_FRIENDS(ProcessModel, DataStream)
        ISCORE_SERIALIZE_FRIENDS(ProcessModel, JSONObject)
        MODEL_METADATA_IMPL(Tutorial::ProcessModel)

        Q_OBJECT
    public:
        ProcessModel(const TimeValue& duration,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);

        template<typename Impl>
        ProcessModel(Deserializer<Impl>& vis, QObject* parent) :
            Process::ProcessModel{vis, parent}
        {
            vis.writeTo(*this);
        }

    private:
        ProcessModel(const ProcessModel& source,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);

        QString prettyName() const override;
        void startExecution() override;
        void stopExecution() override;
        void reset() override;
        ProcessStateDataInterface*startStateData() const override;
        ProcessStateDataInterface*endStateData() const override;
        Selection selectableChildren() const override;
        Selection selectedChildren() const override;
        void setSelection(const Selection& s) const override;

        void setDurationAndScale(const TimeValue& newDuration) override;
        void setDurationAndGrow(const TimeValue& newDuration) override;
        void setDurationAndShrink(const TimeValue& newDuration) override;
};
}
