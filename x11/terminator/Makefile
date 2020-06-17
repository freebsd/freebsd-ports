# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	terminator
PORTVERSION=	1.92
PORTREVISION=	3
CATEGORIES=	x11 python
MASTER_SITES=	https://github.com/gnome-terminator/terminator/releases/download/v${PORTVERSION}/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Multiple GNOME terminals in one window

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/libkeybinder-3.0.so:x11/keybinder-gtk3 \
		${LOCALBASE}/lib/libnotify.so:devel/libnotify \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		gnome python:3.5+ shebangfix
USE_GNOME=	intltool pygobject3 vte3
USE_PYTHON=	autoplist distutils

PYDISTUTILS_PKGNAME=	Terminator

INSTALLS_ICONS=	yes

SHEBANG_FILES=	terminator.wrapper
bash_CMD=	${SH}

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes
NLS_USES=		gettext

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MNLS}
PYDISTUTILS_SETUP+=	--without-gettext
post-patch:
	${CP} ${WRKSRC}/data/terminator.desktop.in ${WRKSRC}/data/terminator.desktop
	${REINPLACE_CMD} -e 's/^_//' ${WRKSRC}/data/terminator.desktop
	${CP} ${WRKSRC}/data/terminator.appdata.xml.in ${WRKSRC}/data/terminator.appdata.xml
	${REINPLACE_CMD} \
		-e 's|<_|<|' \
		-e 's|</_|</|' \
		${WRKSRC}/data/terminator.appdata.xml
.endif

PYDISTUTILS_SETUP+=	--without-icon-cache

.include <bsd.port.post.mk>
