# New ports collection makefile for:    gsynaptics
# Date created:				2006-03-19
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gsynaptics
PORTVERSION=	0.9.9
PORTREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	gsynaptics/21527

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME Synaptics Touchpad setting tool

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USE_GNOME=	lthack intlhack intltool pkgconfig gtk20 libgnome libglade2 libgnomeui
USE_ICONV=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gsynaptics.1 gsynaptics-init.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${LOCALBASE}/lib/xorg/modules/input/synaptics_drv.so:${PORTSDIR}/x11-drivers/xf86-input-synaptics

.include <bsd.port.post.mk>
