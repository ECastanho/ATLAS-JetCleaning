#ifndef QUICK_ANA__EVENT_INFO_IS_DATA_H
#define QUICK_ANA__EVENT_INFO_IS_DATA_H

//        Copyright Iowa State University 2015.
//                  Author: Nils Krumnack
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Please feel free to contact me (nils.erik.krumnack@cern.ch) for bug
// reports, feature suggestions, praise and complaints.


#include <QuickAna/Global.h>

#include <QuickAna/AnaTool.h>

namespace ana
{
  /// \brief this tool checks whether the isData flag in the input
  /// event matches the isData flag from configuration

  class EventInfoIsData : public AnaTool
  {
    //
    // public interface
    //

    ASG_TOOL_CLASS (EventInfoIsData, ana::IAnaTool)


    /// \brief test the invariant of this object
    /// \par Guarantee
    ///   no-fail
  public:
    void testInvariant () const;


    /// \brief standard constructor
    /// \par Guarantee
    ///   strong
    /// \par Failures
    ///   out of memory II
  public:
    EventInfoIsData (const std::string& name, bool isData = false);


    /// effects: apply this analysis tool to the objects
    /// guarantee: basic
    /// failures: tool dependent
  public:
    virtual StatusCode execute (IEventObjects& objects) override;


    /// \copydoc IAnaTool::setObjectType
    /// \sa      IAnaTool::setObjectType
  public:
    virtual StatusCode
    setObjectType (ObjectType type, const std::string& workingPoint) override;

    /// \copydoc IAnaTool::step
    /// \sa      IAnaTool::step
  public:
    virtual AnalysisStep step () const override;

    /// \copydoc IAnaTool::inputTypes
    /// \sa      IAnaTool::inputTypes
  public:
    virtual unsigned inputTypes () const override;


    /// \copydoc IAnaTool::outputTypes
    /// \sa      IAnaTool::outputTypes
  public:
    virtual unsigned outputTypes () const override;



    //
    // private interface
    //

    /// \brief whether we already checked one of the events
    ///
    /// for performance reasons we only check the first event, and
    /// skip the rest
  private:
    bool m_checkedInput = false;

    /// \brief whether we expect this to be data
  private:
    bool m_isData = false;
  };
}

#endif
