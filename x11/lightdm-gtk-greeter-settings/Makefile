# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lightdm-gtk-greeter-settings
PORTVERSION=	1.2.2
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Settings editor for LightDM GTK+ Greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lightdm-gtk-greeter:x11/lightdm-gtk-greeter \
		${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.38:devel/py-python-distutils-extra@${PY_FLAVOR}
LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm

USES=		gettext-tools gnome python
USE_GNOME=	intltool pygobject3
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes
PLIST_FILES=	${PYTHON_SITELIBDIR}/lightdm_gtk_greeter_settings/installation_config.py
PYDISTUTILS_INSTALLARGS+=	--xfce-integration

post-patch:
	@${RM} ${WRKSRC}/bin/lightdm-gtk-greeter-settings-pkexec.orig
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		${WRKSRC}/bin/lightdm-gtk-greeter-settings-pkexec \
		${WRKSRC}/lightdm_gtk_greeter_settings/helpers.py \
		${WRKSRC}/setup.py

.include <bsd.port.pre.mk>

# PYDISTUTILS_INSTALLNOSINGLE is deprecated so...
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
