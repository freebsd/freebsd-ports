# New ports collection makefile for:	wxgtk2-utils-devel
# Date created:         		June 27, 2004
# Whom:					fjoe@FreeBSD.ORG
#
# $FreeBSD$
#

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	The wxWidgets GUI toolkit utils (devel version)

.if defined(WITH_UNICODE)
WXGTK_FLAVOR=	gtk2-unicode-utils
.else
WXGTK_FLAVOR=	gtk2-utils
.endif

MASTERDIR=	${.CURDIR}/../wxgtk2-devel

.include "${MASTERDIR}/Makefile"
