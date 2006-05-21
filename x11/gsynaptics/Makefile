# New ports collection makefile for:    gsynaptics
# Date created:				2006-03-19
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gsynaptics
PORTVERSION=	0.9.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	gsynaptics/19524

MAINTAINER=	nork@FreeBSD.org
COMMENT=	GNOME Synaptics Touchpad setting tool

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${PREFIX}/lib/modules/input/synaptics_drv.o:${PORTSDIR}/x11-servers/synaptics

BROKEN=		Configure fails

USE_GNOME=	lthack intlhack intltool pkgconfig gtk20 libgnome libglade2
USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

MAN1=		gsynaptics.1 gsynaptics-init.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
