# Ports collection Makefile for:	rox-pager
# Date created:				Jan 24 2004
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		rox-pager
PORTVERSION=		1.0.0
CATEGORIES=		x11-wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=		pager-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		olgeni@FreeBSD.org
COMMENT=		Pager for the ROX desktop

USE_GNOME=		gtk20 pkgconfig libxml2 libwnck

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
BINARIES=	FreeBSD-ix86
.else
BINARIES=	FreeBSD-${ARCH}
.endif

PLIST_SUB=	BINARIES="${BINARIES}"

do-build:
	@cd ${WRKSRC} && Pager/AppRun --compile

do-install:
	@${MKDIR} ${PREFIX}/apps/Pager
	@cd ${WRKSRC}/Pager && ${CP} -r .DirIcon AppInfo.xml AppRun AppletRun Help Options.xml ${BINARIES} ${PREFIX}/apps/Pager
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/Pager

.include <bsd.port.post.mk>
