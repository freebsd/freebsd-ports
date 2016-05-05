# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	altyo
#PORTVERSION=
DISTVERSION=	0.4_rc19
CATEGORIES=	x11
DISTNAME=	${DISTVERSION}-${GH_ACCOUNT}1

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Drop-down terminal emulator, written in Vala

LICENSE=	GPLv3

BUILD_DEPENDS=	git:devel/git \
		valac:lang/vala

ALL_TARGET=	default

GH_ACCOUNT=	linvinus
GH_PROJECT=	AltYo
GH_TAGNAME=	debian/${DISTVERSION}-${GH_ACCOUNT}1

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_MAKE_ENV=	NLSUPPORT=yes
NLS_USES=	gettext-runtime:run gettext-tools:build

USES=		gmake pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtk30 vte3

post-install:
	-@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
